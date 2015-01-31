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
	static RobotDrive* m_robotDrive;
	static Solenoid* shifter;
	static Encoder* m_driveEncoderLeft;
	static Encoder* m_driveEncoderRight;
	static AnalogInput* yawRate;

	//inTake
	static CANTalon* frontIntakeLeft;
	static CANTalon* frontIntakeRight;
	static CANTalon* rearIntake;
	static DigitalInput* frontIntakeSensor;
	static DigitalInput* rearIntakeSensor;

	//Bin juggler
	static Solenoid* jugglerLift;
	static Solenoid* leftLock;
	static Solenoid* rightLock;
	static Solenoid* leftGrab;
	static Solenoid* rightGrab;

	//Elevator
	static CANTalon* elevatorLeft;
	static CANTalon* elevatorRight;
	static AnalogInput* elevatorSensor;
	static Solenoid* toteConstrictor;

	//Recycler
	static CANTalon* trackArm;
	static DigitalInput* lowerSensor;
	static DigitalInput* upperSensor;
	static void init();

private:

};

#endif
