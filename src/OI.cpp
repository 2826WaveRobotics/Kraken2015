#include "OI.h"
#include "Commands/ShiftHigh.h"

OI::OI()
{
	driverJoystick = new Joystick(1);
	operatorJoystick = new Joystick(2);
	debugJoystick = new Joystick(3);
	debugJoystick2 = new Joystick(4);

	driver_A = new JoystickButton(driverJoystick, 1);
	driver_B = new JoystickButton(driverJoystick, 2);
	driver_X = new JoystickButton(driverJoystick, 3);
	driver_Y = new JoystickButton(driverJoystick, 4);
	driver_LB = new JoystickButton(driverJoystick, 5);
	driver_RB = new JoystickButton(driverJoystick, 6);
	driver_Back = new JoystickButton(driverJoystick, 7);
	driver_Start = new JoystickButton(driverJoystick, 8);
	driver_LJoy = new JoystickButton(driverJoystick, 9);
	driver_RJoy = new JoystickButton(driverJoystick, 10);

	operator_A = new JoystickButton(driverJoystick, 1);
	operator_B = new JoystickButton(driverJoystick, 2);
	operator_X = new JoystickButton(driverJoystick, 3);
	operator_Y = new JoystickButton(driverJoystick, 4);
	operator_LB = new JoystickButton(driverJoystick, 5);
	operator_RB = new JoystickButton(driverJoystick, 6);
	operator_Back = new JoystickButton(driverJoystick, 7);
	operator_Start = new JoystickButton(driverJoystick, 8);
	operator_LJoy = new JoystickButton(driverJoystick, 9);
	operator_RJoy = new JoystickButton(driverJoystick, 10);

	//comment

	driver_X->WhenPressed(new ShiftHigh());
}
