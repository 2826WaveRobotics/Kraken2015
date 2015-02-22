#include "Drive.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

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

	m_rightPID = new RightPID(&r_p, &r_i, &r_d);
	m_leftPID = new LeftPID(&l_p, &l_i, &l_d);
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
	m_robotDrive->ArcadeDrive(left,right);
}

void Drive::SetDriveDistance(double distance){

}
double Drive::GetDistanceTravelled(){
	return 0; //temporary so it won't be an error
}

double Drive::GetLeftEncoder(){
	return m_driveEncoderLeft->Get();
}
double Drive::GetRightEncoder(){
	return m_driveEncoderRight->Get();
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
