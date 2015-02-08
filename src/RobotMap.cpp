#include "RobotMap.h"
#include "WaveConstants.h"

#define PRACTICE_BOT

#ifdef PRACTICE_BOT

	int CANTalon_leftDrive1 = 0;
	int CANTalon_leftDrive2 = 1;
	int CANTalon_rightDrive1 = 2;
	int CANTalon_rightDrive2 = 3;
	int CANTalon_elevatorLeft = 4;
	int CANTalon_elevatorRight = 5;
	int CANTalon_trackArm = 6;
	int CANTalon_frontIntakeLeft = 20;
	int CANTalon_frontIntakeRight = 19;
	int CANTalon_rearIntake = 9;

#endif

#ifdef COMPETITION_BOT

	int CANTalon_leftDrive1 = 10;
	int CANTalon_leftDrive2 = 11;
	int CANTalon_rightDrive1 = 12;
	int CANTalon_rightDrive2 = 13;
	int CANTalon_elevatorLeft = 14;
	int CANTalon_elevatorRight = 15;
	int CANTalon_trackArm = 16;
	int CANTalon_frontIntakeLeft = 17;
	int CANTalon_frontIntakeRight = 18;
	int CANTalon_rearIntake = 19;

#endif

Compressor* RobotMap::compressor = NULL;
CANTalon* RobotMap::leftDrive1 = NULL;
CANTalon* RobotMap::leftDrive2 = NULL;
CANTalon* RobotMap::rightDrive1 = NULL;
CANTalon* RobotMap::rightDrive2 = NULL;
RobotDrive* RobotMap::m_robotDrive = NULL;
Solenoid* RobotMap::shifter = NULL;
CANTalon* RobotMap::elevatorLeft = NULL;
CANTalon* RobotMap::elevatorRight = NULL;
AnalogInput* RobotMap::elevatorSensor = NULL;
CANTalon* RobotMap::trackArm= NULL;
CANTalon* RobotMap::frontIntakeLeft= NULL;
CANTalon* RobotMap::frontIntakeRight= NULL;
CANTalon* RobotMap::rearIntake= NULL;
DigitalInput* RobotMap::lowerSensor= NULL;
DigitalInput* RobotMap::upperSensor= NULL;
DigitalInput* RobotMap::frontIntakeSensor= NULL;
DigitalInput* RobotMap::rearIntakeSensor= NULL;
Encoder* RobotMap::m_driveEncoderLeft= NULL;
Encoder* RobotMap::m_driveEncoderRight= NULL;
AnalogInput* RobotMap::yawRate = NULL;
Solenoid* RobotMap::jugglerCylinder = NULL;
Solenoid* RobotMap::leftLock = NULL;
Solenoid* RobotMap::rightLock = NULL;
Solenoid* RobotMap::leftGrab = NULL;
Solenoid* RobotMap::rightGrab = NULL;
Solenoid* RobotMap::handleHolder = NULL;



void RobotMap::init() {

	compressor = new Compressor(0);

	leftDrive1 = new CANTalon(CANTalon_leftDrive1);
	leftDrive2 = new CANTalon(CANTalon_leftDrive2);
	rightDrive1 = new CANTalon(CANTalon_rightDrive1);
	rightDrive2 = new CANTalon(CANTalon_rightDrive2);
	elevatorLeft = new CANTalon(CANTalon_elevatorLeft);
	elevatorRight = new CANTalon(CANTalon_elevatorRight);
	trackArm = new CANTalon(CANTalon_trackArm);
	frontIntakeLeft = new CANTalon(CANTalon_frontIntakeLeft);
	frontIntakeRight = new CANTalon(CANTalon_frontIntakeRight);
	rearIntake = new CANTalon(CANTalon_rearIntake);

	m_robotDrive = new RobotDrive(leftDrive1, leftDrive2, rightDrive1, rightDrive2);

	shifter = new Solenoid(0, 0);
	jugglerCylinder = new Solenoid(0,1);
	leftLock = new Solenoid(0,2);
	rightLock = new Solenoid(0,3);
	leftGrab = new Solenoid(0,4);
	rightGrab = new Solenoid(0,5);
	handleHolder = new Solenoid(0,6);

	elevatorSensor = new AnalogInput(0);
	yawRate = new AnalogInput(1);

	lowerSensor = new DigitalInput (0);
	upperSensor = new DigitalInput (1);
	frontIntakeSensor = new DigitalInput (2);
	rearIntakeSensor = new DigitalInput (3);

	m_driveEncoderLeft = new Encoder (4,5, false);//last parameter is reverse direction
	m_driveEncoderRight = new Encoder (6,7, false);//last parameter is reverse direction
	}
