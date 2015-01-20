#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {

public:

	//Drive
	static CANTalon* leftDrive1;
	static CANTalon* leftDrive2;
	static CANTalon* rightDrive1;
	static CANTalon* rightDrive2;
	static Solenoid* shifter;

	//Elevator
	static CANTalon* elevatorLeft;
	static CANTalon* elevatorRight;
	static AnalogInput* elevatorSensor;

	static void init();

private:

};

#endif
