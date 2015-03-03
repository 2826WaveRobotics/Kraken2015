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
	static DigitalInput* rearIntakeSensor;
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

//	static DigitalInput* DIO0; // for testing purposes
//	static DigitalInput* DIO1;
//	static DigitalInput* DIO2;
//	static DigitalInput* DIO3;
	static DigitalInput* DIO4;
	static DigitalInput* DIO5;
	static DigitalInput* DIO6;
	static DigitalInput* DIO7;
	static DigitalInput* DIO8;
	static DigitalInput* DIO9; // for testing purposes

	static void init();

private:

};

#endif
