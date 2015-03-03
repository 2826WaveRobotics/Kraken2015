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

	if(binUpperSensor->Get() == 0){
		return true;
	}
	else{
		return false;
	}
}

bool Recycler::isLowerSensorTripped() {
	if(binLowerSensor->Get() == 0){
		return true;
	}
	else{
		return false;
	}
}

void Recycler::SetRecycleMotors(float speed) {
	std::cout << "Speed: " << speed << std::endl;
	if(isLowerSensorTripped() && speed < 0){ // lower is tripped, but we're going up
		speed = 0;
	}
	else if(isUpperSensorTripped() && speed > 0){ // upper is tripped, but we're going down
		speed = 0;
	}

	trackArmLeft->Set(speed);
	trackArmRight->Set(-speed);
}

void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Recycler::HandleHold(bool open){
	handleHolder->Set(open);
}
