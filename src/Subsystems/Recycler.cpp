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
	m_binSensor = RobotMap::autoBinSensor;
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
	//std::cout << "Speed: " << speed << std::endl;
	if(isLowerSensorTripped() && speed < 0){ // lower is tripped, but we're going up
		std::cout << "Lower bound"<< std::endl;
		speed = 0;
	}
	else if(isUpperSensorTripped() && speed > 0){ // upper is tripped, but we're going down
		std::cout << "upper bound"<< std::endl;
		speed = 0;
	}

	trackArmLeft->Set(-speed);
	trackArmRight->Set(speed);


	std::cout << "Recycler Amps Left: " << trackArmLeft->GetOutputCurrent() <<
			"\tRight: " << trackArmRight->GetOutputCurrent() <<
			"\tVolts Left : " << trackArmLeft->GetOutputVoltage() <<
			"\tRight: " << trackArmRight->GetOutputVoltage() << std::endl;
}
double Recycler::GetCurrent(){
	return (trackArmLeft->GetOutputCurrent() + trackArmRight->GetOutputCurrent()) / 2;
}
void Recycler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Recycler::HandleHold(bool open){
	handleHolder->Set(open); //cylinders switched default for Wisc Reg to be in compliance
}
void Recycler::ToggleHandleHolder(){
	std::cout << "ToggleHandleHolder: Begin! State is: " << handleHolder->Get() << std::endl;

	handleHolder->Set(!handleHolder->Get());

	std::cout << "Current State is Now: " << handleHolder->Get() << std::endl;
}

bool Recycler::isBinSensed()
{
	return !m_binSensor->Get();
}
