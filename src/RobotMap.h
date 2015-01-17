#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {

public:

	//Drive
	static CANTalon* leftDrive;
	static CANTalon* rightDrive;
	static Solenoid* shifter;

	static void init();

private:

};

#endif
