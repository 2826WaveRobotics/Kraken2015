#include "Recycler.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

Recycler::Recycler() :
Subsystem("Recycler")
{

	trackArmLeft = RobotMap::trackArmLeft;
	trackArmRight = RobotMap::trackArmRight;
	binLowerSensor = RobotMap::binLowerSensor;
	binUpperSensor = RobotMap::binUpperSensor;
	handleHolder = RobotMap::handleHolder;

}

bool Recycler::isUpperSensorTripped(){

	if(binUpperSensor->Get()==true) //tripped
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Recycler::isLowerSensorTripped() {
	if(binLowerSensor->Get()==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Recycler::SetRecycleMotors(float speed) {
	trackArmLeft->Set(speed);
	trackArmRight->Set(-speed);
}

void Recycler::SetHandleHolder(bool position){
	handleHolder->Set(position);
}


void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

