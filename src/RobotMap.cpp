#include "RobotMap.h"
#include "WaveConstants.h"


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
Solenoid* RobotMap::jugglerLift = NULL;
Solenoid* RobotMap::leftLock = NULL;
Solenoid* RobotMap::rightLock = NULL;
Solenoid* RobotMap::leftGrab = NULL;
Solenoid* RobotMap::rightGrab = NULL;
Solenoid* RobotMap::toteConstrictor = NULL;


void RobotMap::init() {

	leftDrive1 = new CANTalon(0);
	leftDrive2 = new CANTalon(1);
	rightDrive1 = new CANTalon(2);
	rightDrive2 = new CANTalon(3);
	elevatorLeft = new CANTalon(4);
	elevatorRight = new CANTalon(5);
	trackArm = new CANTalon(6);
	frontIntakeLeft = new CANTalon(7);
	frontIntakeRight = new CANTalon(8);
	rearIntake = new CANTalon(9);

	m_robotDrive = new RobotDrive(leftDrive1, leftDrive2, rightDrive1, rightDrive2);

	shifter = new Solenoid(0, 0);
	jugglerLift = new Solenoid(0,1);
	leftLock = new Solenoid(0,2);
	rightLock = new Solenoid(0,3);
	leftGrab = new Solenoid(0,4);
	rightGrab = new Solenoid(0,5);
	toteConstrictor = new Solenoid(0,6);

	elevatorSensor = new AnalogInput(0);
	yawRate = new AnalogInput(1);

	lowerSensor = new DigitalInput (0);
	upperSensor = new DigitalInput (1);
	frontIntakeSensor = new DigitalInput (2);
	rearIntakeSensor = new DigitalInput (3);

	m_driveEncoderLeft = new Encoder (4,5, false);//last parameter is reverse direction
	m_driveEncoderRight = new Encoder (6,7, false);//last parameter is reverse direction
	}
