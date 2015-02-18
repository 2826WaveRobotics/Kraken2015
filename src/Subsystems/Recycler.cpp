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

}

bool Recycler::isUpperSensorTripped(){

	return binUpperSensor->Get();
}

bool Recycler::isLowerSensorTripped() {
	return binLowerSensor->Get();
}


void Recycler::SetRecycleMotors(float speed) {
	trackArmLeft->Set(speed);
	trackArmRight->Set(-speed);
}

void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

