#include "Drive.h"
#include "../RobotMap.h"

Drive::Drive() :
		PIDSubsystem("Drive", 1.0, 0.0, 0.0)
{
 // insert motor controllers, sensors, and everything else in here
}

void Drive::InitDefaultCommand()
{

}

void Drive::ShiftGear(bool highGear)
{

}

void Drive::DriveWithJoysticks(float left, float right)
{

}
