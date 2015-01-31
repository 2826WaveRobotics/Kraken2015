#include "Recycler.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

Recycler::Recycler() :
Subsystem("Recycler")
{

	trackArm = RobotMap::trackArm;
	lowerSensor = RobotMap::lowerSensor;
	upperSensor = RobotMap::upperSensor;

}

bool Recycler::isUpperSensorTripped(){

	if(upperSensor->Get()==true) //tripped
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Recycler::isLowerSensorTripped() {
	if(lowerSensor->Get()==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void	Recycler::SetRecycleMotors(float speed) {
	trackArm->Set(speed);
}


void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

