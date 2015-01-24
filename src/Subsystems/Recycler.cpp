#include "Recycler.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

Recycler::Recycler() :
Subsystem("Recycler")
{

	trackArmL = RobotMap::trackArmL;
	trackArmR = RobotMap::trackArmR;
	lowerSensor = RobotMap::lowerSensor;
	upperSensor = RobotMap::upperSensor;
	canGrabber = RobotMap::canGrabber;

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
	trackArmL->Set(speed);
	trackArmR->Set(-speed);
	}
void Recycler::canControl(bool grab){
	if(grab){
		canGrabber->Set(On);
	}
	else{
		canGrabber->Set(Off);
	}
}


void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

