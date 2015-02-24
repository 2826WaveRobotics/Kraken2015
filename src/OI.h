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
	bool GetDebugJoystickButton(int button);
	void checkInput();

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


	Joystick* debugJoystick2;

	bool m_allowHumanInput;

};

#endif
