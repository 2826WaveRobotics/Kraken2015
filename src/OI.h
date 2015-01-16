#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	OI();
	Joystick* getDriverJoystick();
	Joystick* getOperatorJoystick();
	Joystick* getDebugJoystick();
	Joystick* getDebugJoystick2();

private:

	Joystick* driverJoystick;
	JoystickButton* driver_RJoy;
	JoystickButton* driver_LJoy;
	JoystickButton* driver_Start;
	JoystickButton* driver_Back;
	JoystickButton* driver_RB;
	JoystickButton* driver_LB;
	JoystickButton* driver_A;
	JoystickButton* driver_B;
	JoystickButton* driver_X;
	JoystickButton* driver_Y;

	Joystick* operatorJoystick;
	JoystickButton* operator_RJoy;
	JoystickButton* operator_LJoy;
	JoystickButton* operator_Start;
	JoystickButton* operator_Back;
	JoystickButton* operator_RB;
	JoystickButton* operator_LB;
	JoystickButton* operator_A;
	JoystickButton* operator_B;
	JoystickButton* operator_X;
	JoystickButton* operator_Y;

	Joystick* debugJoystick;
	JoystickButton* debug_1;
	JoystickButton* debug_2;
	JoystickButton* debug_3;
	JoystickButton* debug_4;
	JoystickButton* debug_5;
	JoystickButton* debug_6;
	JoystickButton* debug_7;
	JoystickButton* debug_8;
	JoystickButton* debug_9;
	JoystickButton* debug_10;
	JoystickButton* debug_11;
	JoystickButton* debug_12;
	JoystickButton* debug_13;
	JoystickButton* debug_14;
	JoystickButton* debug_15;
	JoystickButton* debug_16;
	JoystickButton* debug_17;
	JoystickButton* debug_18;
	JoystickButton* debug_19;
	JoystickButton* debug_20;
	JoystickButton* debug_21;
	JoystickButton* debug_22;
	JoystickButton* debug_23;
	JoystickButton* debug_24;
	JoystickButton* debug_25;
	JoystickButton* debug_26;
	JoystickButton* debug_27;
	JoystickButton* debug_28;
	JoystickButton* debug_29;
	JoystickButton* debug_30;
	JoystickButton* debug_31;
	JoystickButton* debug_32;


	Joystick* debugJoystick2;

};

#endif
