#include "RobotMap.h"
#include "WaveConstants.h"
#include "stdlib.h"

#define PRACTICE_BOT

#ifdef COMPETITION_BOT

	int CANTalon_leftDrive1 = 19;
	int CANTalon_leftDrive2 = 20;
	int CANTalon_rightDrive1 = 2;
	int CANTalon_rightDrive2 = 3;
	int CANTalon_elevatorLeft = 8;
	int CANTalon_elevatorRight = 11;
	int CANTalon_trackArmLeft = 15;
	int CANTalon_trackArmRight = 18;
	int CANTalon_frontIntakeLeft = 12;
	int CANTalon_frontIntakeRight = 13;
	int CANTalon_rearIntake = 10;

#endif

#ifdef PRACTICE_BOT

	int CANTalon_leftDrive1 = 14; //coast
	int CANTalon_leftDrive2 = 26; //coast
	int CANTalon_rightDrive1 = 1; //coast
	int CANTalon_rightDrive2 = 27; //coast
	int CANTalon_elevatorLeft = 25; //brake
	int CANTalon_elevatorRight = 5; //brake
	int CANTalon_trackArmLeft = 17; //brake
	int CANTalon_trackArmRight = 16; //brake
	int CANTalon_frontIntakeLeft = 9; //brake
	int CANTalon_frontIntakeRight = 4; //brake
	int CANTalon_rearIntake = 7; //coast
#endif

Compressor* RobotMap::compressor = NULL;
PowerDistributionPanel* RobotMap::PDBoard = NULL;
CANTalon* RobotMap::leftDrive1 = NULL;
CANTalon* RobotMap::leftDrive2 = NULL;
CANTalon* RobotMap::rightDrive1 = NULL;
CANTalon* RobotMap::rightDrive2 = NULL;
RobotDrive* RobotMap::m_robotDrive = NULL;
Solenoid* RobotMap::shifter = NULL;
CANTalon* RobotMap::elevatorLeft = NULL;
CANTalon* RobotMap::elevatorRight = NULL;
AnalogInput* RobotMap::elevatorSensor = NULL;
CANTalon* RobotMap::trackArmLeft= NULL;
CANTalon* RobotMap::trackArmRight= NULL;
CANTalon* RobotMap::frontIntakeLeft= NULL;
CANTalon* RobotMap::frontIntakeRight= NULL;
CANTalon* RobotMap::rearIntake= NULL;
DigitalInput* RobotMap::binLowerSensor= NULL;
DigitalInput* RobotMap::binUpperSensor= NULL;
DigitalInput* RobotMap::frontIntakeSensor= NULL;
DigitalInput* RobotMap::humanWallSensor = NULL;
Encoder* RobotMap::m_driveEncoderLeft= NULL;
Encoder* RobotMap::m_driveEncoderRight= NULL;
AnalogInput* RobotMap::yawRate = NULL;
Solenoid* RobotMap::jugglerCylinder = NULL;
Solenoid* RobotMap::leftLock = NULL;
Solenoid* RobotMap::rightLock = NULL;
Solenoid* RobotMap::leftHook = NULL;
Solenoid* RobotMap::rightHook = NULL;
Solenoid* RobotMap::toteLocker = NULL;
Solenoid* RobotMap::handleHolder = NULL;

//DigitalInput* RobotMap::DIO0 = NULL; // for testing purposes
//DigitalInput* RobotMap::DIO1 = NULL;
//DigitalInput* RobotMap::DIO2 = NULL;
//DigitalInput* RobotMap::DIO3 = NULL;
DigitalInput* RobotMap::DIO4 = NULL;
DigitalInput* RobotMap::DIO5 = NULL;
DigitalInput* RobotMap::DIO6 = NULL;
DigitalInput* RobotMap::DIO7 = NULL;
DigitalInput* RobotMap::DIO8 = NULL;
DigitalInput* RobotMap::DIO9 = NULL; // for testing purposes



void RobotMap::init() {

	compressor = new Compressor(0);
	PDBoard = new PowerDistributionPanel();

	leftDrive1 = new CANTalon(CANTalon_leftDrive1);
	leftDrive2 = new CANTalon(CANTalon_leftDrive2);
	rightDrive1 = new CANTalon(CANTalon_rightDrive1);
	rightDrive2 = new CANTalon(CANTalon_rightDrive2);
	elevatorLeft = new CANTalon(CANTalon_elevatorLeft);
	elevatorRight = new CANTalon(CANTalon_elevatorRight);
	trackArmLeft = new CANTalon(CANTalon_trackArmLeft);
	trackArmRight = new CANTalon(CANTalon_trackArmRight);
	frontIntakeLeft = new CANTalon(CANTalon_frontIntakeLeft);
	frontIntakeRight = new CANTalon(CANTalon_frontIntakeRight);
	rearIntake = new CANTalon(CANTalon_rearIntake);

	m_robotDrive = new RobotDrive(leftDrive1, leftDrive2, rightDrive1, rightDrive2);

	shifter = new Solenoid(0,4);
	jugglerCylinder = new Solenoid(0,3);
	leftLock = new Solenoid(0,1);
	rightLock = new Solenoid(0,5);
	leftHook = new Solenoid(0,6);
	rightHook = new Solenoid(0,2);
	toteLocker = new Solenoid(0,0);
	handleHolder = new Solenoid(0,7);

	elevatorSensor = new AnalogInput(0);
	yawRate = new AnalogInput(1);

	binLowerSensor = new DigitalInput (4); // 4
	binUpperSensor = new DigitalInput (5);
	frontIntakeSensor = new DigitalInput (6);
	humanWallSensor = new DigitalInput (7);



	m_driveEncoderLeft = new Encoder (0,1, false);//last parameter is reverse direction
	m_driveEncoderRight = new Encoder (2,3, true);//last parameter is reverse direction

	}
