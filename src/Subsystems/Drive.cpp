#include "Drive.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"
#include "../Robot.h"

namespace
{
double r_p =1.0;
double r_i = 0.0;
double r_d = 0.0;

double l_p = 1.0;
double l_i = 0.0;
double l_d = 0.0;
}

Drive::Drive() :
						Subsystem("Drive")
{
	m_robotDrive = RobotMap::m_robotDrive;
	// insert motor controllers, sensors, and everything else in here
	m_driveEncoderLeft = RobotMap::m_driveEncoderLeft;
	m_driveEncoderRight = RobotMap::m_driveEncoderRight;
	m_shifter = RobotMap::shifter;
	m_inchesToDrive = 0;
	m_distanceDriven = 0;

	m_left1 = RobotMap::leftDrive1;
	m_left2 = RobotMap::leftDrive2;
	m_right1 = RobotMap::rightDrive1;
	m_right2 = RobotMap::rightDrive2;

	//m_rightPID = new RightPID(&r_p, &r_i, &r_d);
	//m_leftPID = new LeftPID(&l_p, &l_i, &l_d);
	m_robotDrive->SetSafetyEnabled(false);
}

void Drive::InitDefaultCommand()
{

}

void Drive::ShiftGear(bool highGear)
{
	if (highGear)
	{
		m_shifter->Set(On);
	}
	else
	{
		m_shifter->Set(Off);
	}
}

void Drive::SetEncodersContinuous(bool cont = true)
{
	m_leftPID->SetContinuous(cont);
	m_leftPID->SetContinuous(cont);
}

void Drive::DriveWithJoysticks(float left, float right)
{
	std::cout << "  Drive: " << left << ", " << right << std::endl;
	m_robotDrive->ArcadeDrive(left,right);
}

void Drive::SetDriveDistance(double distance){

}

double Drive::GetDistanceTravelled(){
	return (GetLeftDistanceTravelled() + GetRightDistanceTravelled())/2;
}
double Drive::GetLeftDistanceTravelled(){
	return GetLeftEncoder()*circumference*ticksPerWheel;
}
double Drive::GetRightDistanceTravelled(){
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

void Drive::Enable()
{
	m_leftPID->Enable();
	m_rightPID->Enable();
}

void Drive::Disable()
{
	m_leftPID->Disable();
	m_rightPID->Disable();
}

void Drive::Reset()
{
	m_leftPID->Reset();
	m_rightPID->Reset();
}

void Drive::SetDriveSetpoint(double setpoint)
{
	m_leftPID->SetSetpoint(setpoint);
	m_rightPID->SetSetpoint(setpoint);
}

void Drive::SetLeftSetpoint(double setpoint)
{
	m_leftPID->SetSetpoint(setpoint);
}

void Drive::SetRightSetpoint(double setpoint)
{
	m_rightPID->SetSetpoint(setpoint);
}

void Drive::SetDrivePID(double p, double i, double d)
{
	m_leftPID->SetPID(p, i, d);
	m_rightPID->SetPID(p, i, d);
}

void Drive::SetSidePower(double left,double right){
	m_left1->Set(left);
	m_left2->Set(left);
	m_right1->Set(-right);
	m_right2->Set(-right);
}

void Drive::SetPower(double power){
	m_left1->Set(power);
	m_left2->Set(power);
	m_right1->Set(-power);
	m_right2->Set(-power);
}
void Drive::SetCoefPower(double power){
	//double leftCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(2) / 5); // for checking the coefficients from the potentiometers
	//double rightCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(3) / 5);
	double leftCoef = .8;
	double rightCoef = 1;
	double leftPower = power*leftCoef;
	double rightPower = power*rightCoef;
	//	double rightPower = power -.063;
	//	double leftPower = power;// - .03;   shifted left today

	std::cout << "Left Ticks: " << GetLeftEncoder() << "\tRight Ticks: " << GetRightEncoder() << "\tLeft Distance: " <<
			GetLeftDistanceTravelled() << "\tRight Distance: " << GetRightDistanceTravelled() <<
			"\tLeft Coef: " << leftCoef << "\tRight Coef: " << rightCoef << "\tLeft Power: " << leftPower << "\tRight Power: " << rightPower << std::endl;

	m_left1->Set(leftPower);
	m_left2->Set(leftPower);
	m_right1->Set(-rightPower);
	m_right2->Set(-rightPower);
}
