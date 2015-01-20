#include "Drive.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

Drive::Drive() :
		PIDSubsystem("Drive", 1.0, 0.0, 0.0)
{
	m_robotDrive = new RobotDrive(RobotMap::leftDrive1, RobotMap::leftDrive2, RobotMap::rightDrive1, RobotMap::rightDrive2);
 // insert motor controllers, sensors, and everything else in here
}

void Drive::InitDefaultCommand()
{

}

void Drive::ShiftGear(bool highGear)
{
	if (highGear)
		{
			RobotMap::shifter->Set(On);
		}
		else {
			RobotMap::shifter->Set(Off);
		}
}

void Drive::DriveWithJoysticks(float left, float right)
{
	m_robotDrive->ArcadeDrive(left,right);
}

double Drive::ReturnPIDInput()
{
	return RobotMap::leftDrive1->Get();
}

void Drive::UsePIDOutput(double)
{

}
