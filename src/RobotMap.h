#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"


class RobotMap {

public:

	//Compressor
	static Compressor* compressor;

	//Drive
	static CANTalon* leftDrive1;
	static CANTalon* leftDrive2;
	static CANTalon* rightDrive1;
	static CANTalon* rightDrive2;
	static RobotDrive* m_robotDrive;
	static Solenoid* shifter;
	static Encoder* m_driveEncoder;
	static AnalogInput* yawRate;
	static Encoder* m_driveEncoderLeft;
	static Encoder* m_driveEncoderRight;

	//inTake
	static CANTalon* frontIntakeLeft;
	static CANTalon* frontIntakeRight;
	static CANTalon* rearIntake;
	static DigitalInput* frontIntakeSensor;
	static DigitalInput* rearIntakeSensor;

	//Elevator
	static CANTalon* elevatorLeft;
	static CANTalon* elevatorRight;
	static AnalogInput* elevatorSensor;

	//Recycler
	static CANTalon* trackArm;
	static DigitalInput* lowerSensor;
	static DigitalInput* upperSensor;
	static Solenoid* canGrabber;

	//Bin Juggler
	static Solenoid* jugglerLift;
	static Solenoid* leftLock;
	static Solenoid* rightLock;
	static Solenoid* leftGrab;
	static Solenoid* rightGrab;
	static Solenoid* toteConstrictor;

	static void init();

private:

};

#endif
