#include "Elevator.h"
#include "../RobotMap.h"
#include "../Robot.h"

namespace
{
double MaxVolts = Elevator_UpperVolts;
double MinVolts = Elevator_LowerVolts;
}

Elevator::Elevator() :
					 PIDSubsystem("Elevator", 0.26, 0.0, 0.0)
{
	SetAbsoluteTolerance(0.1);
	GetPIDController()->SetContinuous(false);
	//LiveWindow::GetInstance()->AddActuator("ArmPitchWithPID", "PIDSubsystem Controller", GetPIDController());
	GetPIDController()->SetInputRange(MinVolts, MaxVolts); //range on sensor 0-12 volts
	GetPIDController()->SetOutputRange(-1.0, 1.0); //range on motors (comp bot is -1 to 1)
	GetPIDController()->SetAbsoluteTolerance(elevatorTolerance); //plus or minus this voltage

	m_elevatorLeft = RobotMap::elevatorLeft;
	m_elevatorRight = RobotMap::elevatorRight;
	m_elevatorSensor = RobotMap::elevatorSensor;
	m_toteLock = RobotMap::toteLocker;
}

double Elevator::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	//	return m_elevatorSensor->GetAverageVoltage();
	return convertVoltsToInches(m_elevatorSensor->GetVoltage());
}

double Elevator::GetPIDOutput()
{
	//std::cout << "ELevator::GetPIDOutput() -- returning " << GetPIDController()->Get() << std::endl;
	return GetPIDController()->Get();
}


void Elevator::UsePIDOutput(double output) {
	//Enforce virtual limits
	output=checkSoftStops(output, false);

	//std::cout << "ELevator::UsePIDOutput() -- " << -output << std::endl;



	m_elevatorLeft->PIDWrite(output);
	m_elevatorRight->PIDWrite(output);
}

void Elevator::setAbsoluteHeight(double targetHeight) // target height is in inches
{
	PIDController *pid = GetPIDController();
	double currentHeight = getCurrentHeight(); // turning the voltage reading into a usable inch value

	//CalculatePIDs(); // calculates the PID gains for the
	//
	//	if(Robot::oi->GetDebugJoystickButton(17)){ //
	//		//put max value in front of Robot::oi
	//		c_upP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		c_downP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		c_upI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		c_downI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		c_upD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		c_downD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//	}

	//std::cout << "\n\nPup: " << c_upP << "\tPdown: " << c_downP << "\tIup: " << c_upI <<
	//"\tIdown: " << c_downI << "\tDup: " << c_upD << "\tDdown: " << c_downD << "\n\n" << std::endl;

	m_upP = m_downP = .26;
	m_upI = m_downI = m_upD = m_downD = 0;

	if(currentHeight < targetHeight)
	{
		//These are UP gains
		pid->SetPID(m_upP, m_upI, m_upD);
	}
	else
	{
		//These are DOWN gains
		pid->SetPID(m_downP, m_downI, m_downD);
	}

	std::cout << "Power to Elevator: " << (m_elevatorLeft->Get() + m_elevatorRight->Get()) / 2 << std::endl;

	//double setVoltage = convertInchesToVolts(targetHeight); // entire elevator is in inches now

	std::cout << "P: " << GetPIDController()->GetP();
	std::cout << "I: " << GetPIDController()->GetI();
	std::cout << "D: " << GetPIDController()->GetD() << std::endl;

	pid->Disable();
	pid->Reset();
	pid->SetSetpoint(targetHeight); //setpoint is in voltage
	pid->Enable();
	std::cout << "Setpoint: " << pid->GetSetpoint() << "\tTarget: " << targetHeight << std::endl;
}

void Elevator::disablePID()
{
	//std::cout << "ELevator::DisablePID()" << std::endl;
	GetPIDController()->Disable();
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float Elevator::convertVoltsToInches (float volts)
{
	float inches = -6.528 * volts + 36.04;
//	std::cout << "Volts (Received) = " << volts << "\tInches (calced) = " << inches << std::endl;
	//float inches = 6.379 * volts + 3.603; // this was for the sensor that we broke
	return inches;
	std::cout << "inches" << inches << std::endl;
}

//float Elevator::convertInchesToVolts (double inches)
//{
//	float volts = (inches - 36.04) / -6.528;
//	std::cout << "Inches (Received) = " << inches << "\tVolts (calced) = " << volts << std::endl;
//	//float volts = (inches - 3.603) / 6.379; // this was for the sensor that we broke
//	return volts;
//}

float Elevator::getCurrentVoltageOfSensor()
{
	return	m_elevatorSensor->GetVoltage();
}

double Elevator::getCurrentHeight()
{
	double inches = convertVoltsToInches(getCurrentVoltageOfSensor());
	//	std::cout << "Inches: " << inches << std::endl;
	return inches;
}

void Elevator::setElevatorMotors(float speed)
{
	//std::cout << "Elevator Speed: " << speed << std::endl;
	speed=checkSoftStops(speed, true);

	m_elevatorLeft->Set(-speed);
	m_elevatorRight->Set(-speed);
}

double Elevator::checkSoftStops(double desiredOutput, bool invertedOutput)
{
	//Up is negative speed, Down is positive speed
	double currentVolts = getCurrentVoltageOfSensor();
	double currentHeight = convertVoltsToInches(currentVolts);
	if(invertedOutput)
	{
		if((currentHeight > Elevator_UpperStop) && (desiredOutput < 0))
		{//prevent Up movement
			desiredOutput = 0;
		}
		else if((currentHeight < Elevator_LowerStop) && desiredOutput > 0)
		{//prevent Down movement
			desiredOutput = 0;
		}
	}
	else
	{
		if((currentHeight > Elevator_UpperStop) && (desiredOutput > 0))
		{//prevent Up movement
			desiredOutput = 0;
		}
		else if((currentHeight < Elevator_LowerStop) && desiredOutput < 0)
		{//prevent Down movement
			desiredOutput = 0;
		}
	}
	return desiredOutput;
}

float Elevator::getCurrentFeedback_LeftMotor()
{
	return m_elevatorLeft->GetOutputCurrent();
}

float Elevator::getCurrentFeedback_RightMotor()
{
	return m_elevatorRight->GetOutputCurrent();
}

void Elevator::lockTotes(bool lock){
	m_toteLock->Set(lock);
}
void Elevator::toggleLockTotes(){
	bool currentState = m_toteLock->Get();
	if(currentState == true){
		m_toteLock->Set(false);
	}
	else{
		m_toteLock->Set(true);
	}
}
void Elevator::CalculateTotes(){
	//currently not being used
	//originally did math with the current
}
void Elevator::CalculatePIDs(){
	m_numOfTotes = ceil(m_numOfTotes);
	switch(int(m_numOfTotes)){
	case 0:
		m_upP = 1;
		m_downP = 1; // replace the 1s with better values
		break;
	case 1:
		m_upP = 1;
		m_downP = 1;
		break;
	case 2:
		m_upP = 1;
		m_downP = 1;
		break;
	case 3:
		m_upP =1;
		m_downP = 1;
		break;
	case 4:
		m_upP = 1;
		m_downP = 1;
		break;
	case 5:
		m_upP = 1;
		m_downP = 1;
		break;
	case 6:
		m_upP = 1;
		m_downP = 1;
		break;
	default:
		m_upP = 1;
		m_downP = 1;
		break;
	}
	m_upI = m_downI = m_upD = m_downD = 0;
}
void Elevator::SetTotes(bool relative, float totes){
	if(relative){
		m_numOfTotes += totes;
	}
	else{
		m_numOfTotes = totes;
	}
}
float Elevator::GetTotes(){
	return m_numOfTotes;
}

void Elevator::SetPIDs(double _p, double _i, double _d){
	GetPIDController()->SetPID(_p, _i, _d);
}
