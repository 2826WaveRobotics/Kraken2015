#include "RobotMap.h"
#include "WaveConstants.h"


CANTalon* RobotMap::leftDrive1 = NULL;
CANTalon* RobotMap::leftDrive2 = NULL;
CANTalon* RobotMap::rightDrive1 = NULL;
CANTalon* RobotMap::rightDrive2 = NULL;
Solenoid* RobotMap::shifter = NULL;
CANTalon* RobotMap::elevatorLeft = NULL;
CANTalon* RobotMap::elevatorRight = NULL;
AnalogInput* RobotMap::elevatorSensor = NULL;
Talon* RobotMap::trackArmL= NULL;
Talon* RobotMap::trackArmR= NULL;
DigitalInput* RobotMap::lowerSensor= NULL;
DigitalInput* RobotMap::upperSensor= NULL;
Solenoid* RobotMap::canGrabber= NULL;

void RobotMap::init() {

	leftDrive1 = new CANTalon(0);
	leftDrive2 = new CANTalon(1);
	rightDrive1 = new CANTalon(2);
	rightDrive2 = new CANTalon(3);
	elevatorLeft = new CANTalon(4);
	elevatorRight = new CANTalon(5);

	shifter = new Solenoid(0, 0);
	canGrabber = new Solenoid (0,1);

	elevatorSensor = new AnalogInput(0);

	trackArmL = new Talon(1);
	trackArmR = new Talon(2);

	lowerSensor = new DigitalInput (1);
	upperSensor = new DigitalInput (2);

	}
