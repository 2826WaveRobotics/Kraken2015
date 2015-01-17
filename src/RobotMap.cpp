#include "RobotMap.h"


CANTalon* RobotMap::leftDrive = 0;
CANTalon* RobotMap::rightDrive = 0;
Solenoid* RobotMap::shifter = 0;

void RobotMap::init() {

	leftDrive = new CANTalon(0);
	rightDrive = new CANTalon(1);

	shifter = new Solenoid(0, 0);



}
