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
	static Encoder* m_driveEncoder;
	//inTake
	static Talon* frontIntake;
	static Talon* rearIntake;
	static DigitalInput* frontIntakeSensor;
	static DigitalInput* rearIntakeSensor;
	//Elevator
	static CANTalon* elevatorLeft;
	static CANTalon* elevatorRight;
	static AnalogInput* elevatorSensor;

	//Recycler
	static Talon* trackArmL;
	static Talon* trackArmR;
	static DigitalInput* lowerSensor;
	static DigitalInput* upperSensor;
	static Solenoid* canGrabber;

	static void init();

private:

};

#endif
