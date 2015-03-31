#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"


class RobotMap {

public:

	//Compressor
	static Compressor* compressor;

	//CAN Controlled Devices
	static PowerDistributionPanel* PDBoard;

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

	//Intake
	static CANTalon* frontIntakeLeft;
	static CANTalon* frontIntakeRight;
	static CANTalon* rearIntake;
	static DigitalInput* frontIntakeSensor;
	static DigitalInput* autoBinSensor;
	static Solenoid* toteLocker;

	//Elevator
	static CANTalon* elevatorLeft;
	static CANTalon* elevatorRight;
	static AnalogInput* elevatorSensor;

	//Recycler
	static CANTalon* trackArmLeft;
	static CANTalon* trackArmRight;
	static DigitalInput* binLowerSensor;
	static DigitalInput* binUpperSensor;
	static Solenoid* handleHolder;

	//Bin Juggler
	static Solenoid* jugglerCylinder;
	static Solenoid* leftLock;
	static Solenoid* rightLock;
	static Solenoid* leftHook;
	static Solenoid* rightHook;


	static void init();

private:

};

#endif
