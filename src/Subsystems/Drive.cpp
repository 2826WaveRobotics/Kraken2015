#include "Drive.h"
#include "WaveConstants.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"

Drive::Drive() :
PIDSubsystem("Drive",.0246094, 0,.0742188)
{
	SetAbsoluteTolerance(0.1);
	GetPIDController()->SetContinuous(true);
	//LiveWindow::GetInstance()->AddActuator("ArmPitchWithPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetInputRange(-180, 180); //range on max we should ever be off
	GetPIDController()->SetOutputRange(-1.0, 1.0); //range on motors
	GetPIDController()->SetAbsoluteTolerance(0); //plus or minus this voltage

	m_left1 = RobotMap::leftDrive1;
	m_left2 = RobotMap::leftDrive2;
	m_right1 = RobotMap::rightDrive1;
	m_right2 = RobotMap::rightDrive2;

	m_robotDrive = RobotMap::m_robotDrive;
	m_driveEncoderLeft = RobotMap::m_driveEncoderLeft;
	m_driveEncoderRight = RobotMap::m_driveEncoderRight;
	m_shifter = RobotMap::shifter;

	m_inchesToDrive = 0;
	m_distanceDriven = 0;

	m_robotDrive->SetSafetyEnabled(false);

	table = NetworkTable::GetTable("datatable");
	serial_port = new SerialPort(57600,SerialPort::kMXP);
	uint8_t update_rate_hz = 50;
#if defined(ENABLE_AHRS)
	imu = new AHRS(serial_port,update_rate_hz);
#elif defined(ENABLE_IMU_ADVANCED)
	imu = new IMUAdvanced(serial_port,update_rate_hz);
#else // ENABLE_IMU
	imu = new IMU(serial_port,update_rate_hz);
#endif
	if ( imu ) {
		LiveWindow::GetInstance()->AddSensor("IMU", "Gyro", imu);
	}
	first_iteration = true;
}
IMU* Drive::getIMU(){
	return imu;
}
double Drive::ReturnPIDInput()
{
	if(m_mode == mode_straight){
		return imu->GetYaw();
	}
	else if(m_mode == mode_distance){
		return GetDistanceTraveled();
	}
	else if(m_mode == mode_velocity){
		return GetVelocity();
	}
	else{
		return 0;
	}
}
void Drive::DisablePID()
{
	GetPIDController()->Disable();
}
void Drive::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	//SetPower(output);
}
double Drive::GetPIDOutput()
{
	return GetPIDController()->Get();
}

void Drive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}
void Drive::MoveStraight(float direction){
	std::cout << "Drive: Moving straight" << std::endl;
	GetPIDController()->Disable();
	GetPIDController()->Reset();
	GetPIDController()->SetSetpoint(direction); //we are now facing the same way the entire time (zeroYaw())
	GetPIDController()->Enable();
}
void Drive::DriveStraight(double power){
	//std::cout << "Drive: Moving straight with power: " << power << std::endl;
	double correction = Robot::m_drive->GetPIDOutput();
	SetSidePower(power + correction, power - correction);
	double degreesOff = GetSetpoint() - GetYaw();
	std::cout << /*"Correction: " << correction << "\tLeft: " <<
			(power + correction) << "\tRight: " << (power - correction) <<*/ "\tYaw: "
			<< GetYaw() << "\tSetpoint: " << GetSetpoint() <<  "\tOff By: " << degreesOff << std::endl;
}
void Drive::MoveDistance(double distance){
	std::cout << "Drive: Driving " << distance << " inches" << std::endl;
	GetPIDController()->Disable();
	GetPIDController()->Reset();
	GetPIDController()->SetSetpoint(distance); //we are now facing the same way the entire time (zeroYaw())
	GetPIDController()->Enable();
}
void Drive::DriveDistance(double maxPower){
	std::cout << "Drive: Moving with max power: " << maxPower << std::endl;
	double power = Robot::m_drive->GetPIDOutput();
	if(power > maxPower){
		std::cout << "Power to high, resetting it to " << maxPower << std::endl;
		power = maxPower;
	}
	if(power < -maxPower){
		std::cout << "Power to low, resetting it to " << -maxPower << std::endl;
		power = -maxPower;
	}
	SetPower(power);
}
void Drive::Turn(double power){
	//std::cout << "Drive: Moving straight with power: " << power << std::endl;
	double correction = Robot::m_drive->GetPIDOutput();
	double correctedLeftPower =  power + correction;
	double correctedRightPower = power - correction;
	double limit = .6;
	if(correctedLeftPower > limit){
		correctedLeftPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedLeftPower = -limit;
	}
	if(correctedRightPower > limit){
		correctedRightPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedRightPower = -limit;
	}
	SetSidePower(correctedLeftPower, correctedRightPower);
	double degreesOff = fabs(GetSetpoint() - GetYaw());
	std::cout << "Correction: " << correction << "\tLeft: " <<
			correctedLeftPower << "\tRight: " << correctedRightPower << "\tYaw: "
			<< GetYaw() << "\tSetpoint: " << GetSetpoint() <<  "\tOff By: " << degreesOff << std::endl;
}
void Drive::Orient(double degrees){ // degrees are relative to field
	GetPIDController()->Disable();
	GetPIDController()->Reset();
	GetPIDController()->SetSetpoint(degrees); //we want to move straight in whatever direction we are facing
	GetPIDController()->Enable();
}
void Drive::DriveWithJoysticks()
{
	m_turn = Robot::oi->getDriverJoystick()->GetRawAxis(Axis_RX);
	m_throttle = Robot::oi->getDriverJoystick()->GetRawAxis(Axis_LY);
	if(fabs(m_turn) < .075){m_turn = 0; }
	if(fabs(m_throttle) < .075){m_throttle = 0;}
	m_robotDrive->ArcadeDrive(m_throttle,m_turn);
}
void Drive::Shift(bool high){
	if (high) // solenoid defaults changed Mar15
	{
		m_shifter->Set(false);
	}
	else
	{
		m_shifter->Set(true);
	}
}
double Drive::GetDistanceTraveled(){
	return (GetLeftDistanceTraveled() + GetRightDistanceTraveled()) / 2;
}
double Drive::GetLeftDistanceTraveled(){
	return GetLeftEncoder()*circumference*ticksPerWheel;
}
double Drive::GetRightDistanceTraveled(){
	return GetRightEncoder()*circumference*ticksPerWheel;
}

double Drive::GetLeftEncoder(){
	return m_driveEncoderLeft->Get();
}

double Drive::GetRightEncoder(){
	return m_driveEncoderRight->Get();
}

void Drive::ResetEncoders(){
	m_driveEncoderLeft->Reset();
	m_driveEncoderRight->Reset();
}
void Drive::SetSidePower(double left,double right){
	m_left1->Set(-left);
	m_left2->Set(-left);
	m_right1->Set(right);
	m_right2->Set(right);
}

void Drive::SetPower(double power){
	m_left1->Set(-power);
	m_left2->Set(-power);
	m_right1->Set(power);
	m_right2->Set(power);
}
double Drive::GetYaw(){
	return imu->GetYaw();
}
void Drive::SetPIDs(double _P, double _I, double _D){
	GetPIDController()->SetPID(_P,_I,_D);
}

void Drive::PIDReset(){
	GetPIDController()->SetSetpoint(0); // m_autoYaw
	GetPIDController()->Enable();
}
void Drive::GyroReset(){
	GetPIDController()->Disable();
	imu->ZeroYaw();
	GetPIDController()->Reset();
	GetPIDController()->SetSetpoint(0);
	GetPIDController()->Enable();
}
void Drive::ZeroYaw(){
	std::cout << "\n\n\n\n\nResetting Yaw!!!!\n\n\n\n\n\n\n" << std::endl;
	imu->ZeroYaw();
}
void Drive::PrintPIDs(){
	std::cout << "Using PIDs: P: " << GetPIDController()->GetP() << "\tI: " <<
			GetPIDController()->GetI() << "\tD: " << GetPIDController()->GetD() << std::endl;
}
void Drive::SetPIDMode(int mode){
	m_mode = mode;
}

double Drive::GetVelocity(){
	double encoder_LRate = m_driveEncoderLeft->GetRate(); //returns ticks / second
	double encoder_RRate = m_driveEncoderRight->GetRate();
	double averageEncoderRate = (encoder_LRate + encoder_RRate) / 2;
	double velocity = averageEncoderRate*circumference*ticksPerWheel; //turns ticks / second into inches / second
	return velocity;
}
double Drive::CheckPower(double maxPower, double minPower, double distanceToDrive, double midpointMultiplier){ // returns the max power allowed during auto for the distance
	bool forward = distanceToDrive > 0 ? true : false; //if distance is positive, we are moving forward
	double distance = fabs(GetDistanceTraveled());
	double distanceToTarget = fabs(fabs(distanceToDrive) - fabs(distance));
	double powerRange = fabs(maxPower-minPower);

	//using equation f(x) = a(x-b)+c
	double midpoint = fabs(distanceToDrive / 2);
	double c = fabs(maxPower); // higher c makes it ramp up to 1 faster
	double b = midpointMultiplier * midpoint; // b is distance that we achieve max power //number less than 1 will move the peak speed closer to beginning
	double a = c / pow((distanceToDrive - b), 2);

	double modPower = -a * pow((distance-b),2) + c;

	if(modPower < minPower){
		modPower = minPower * (modPower / fabs(modPower));
	}
	//	double modPower = pow(fabs(distanceToTarget)/distanceToDrive, exponent)*actualPower;
	//	modPower = (modPower+minPower)*(distanceToTarget/fabs(distanceToTarget));
	if(!forward){
		modPower = -modPower;
		std::cout << "Return modPower = " << modPower << std::endl;
	}

	return modPower;
}
