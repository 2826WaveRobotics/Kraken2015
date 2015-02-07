#include "OI.h"
#include "Commands/ShiftHigh.h"
#include "Commands/SetElevatorPosition.h"
#include "Commands/SystemTestCommand.h"

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

	JoystickButton* debug_1 = new JoystickButton(debugJoystick, 1);
	JoystickButton* debug_2 = new JoystickButton(debugJoystick, 2);
	JoystickButton* debug_3 = new JoystickButton(debugJoystick, 3);
	JoystickButton* debug_4 = new JoystickButton(debugJoystick, 4);
	JoystickButton* debug_5 = new JoystickButton(debugJoystick, 5);
	JoystickButton* debug_6 = new JoystickButton(debugJoystick, 6);
	JoystickButton* debug_7 = new JoystickButton(debugJoystick, 7);
	JoystickButton* debug_8 = new JoystickButton(debugJoystick, 8);
	JoystickButton* debug_9 = new JoystickButton(debugJoystick, 9);
	JoystickButton* debug_10 = new JoystickButton(debugJoystick, 10);
	JoystickButton* debug_11 = new JoystickButton(debugJoystick, 11);
	JoystickButton* debug_12 = new JoystickButton(debugJoystick, 12);
	JoystickButton* debug_13 = new JoystickButton(debugJoystick2, 1);
	JoystickButton* debug_14 = new JoystickButton(debugJoystick2, 2);
	JoystickButton* debug_15 = new JoystickButton(debugJoystick2, 3);
	JoystickButton* debug_16 = new JoystickButton(debugJoystick2, 4);

	//i can make a comment

	driver_X->WhenPressed(new ShiftHigh());
	driver_A->WhenPressed(new SetElevatorPosition(24.0));
	debug_13->WhileHeld(new SystemTestCommand(Test_leftDrive1));
	debug_14->WhileHeld(new SystemTestCommand(Test_leftDrive2));
	debug_15->WhileHeld(new SystemTestCommand(Test_rightDrive1));
	debug_16->WhileHeld(new SystemTestCommand(Test_rightDrive2));
	debug_1->WhenPressed(new SystemTestCommand(Test_leftLock));
	debug_2->WhenPressed(new SystemTestCommand(Test_rightLock));
	debug_3->WhenPressed(new SystemTestCommand(Test_leftGrab));
	debug_4->WhenPressed(new SystemTestCommand(Test_rightGrab));
	debug_5->WhileHeld(new SystemTestCommand(Test_frontIntakeLeft));
	debug_6->WhileHeld(new SystemTestCommand(Test_frontIntakeRight));
	debug_7->WhenPressed(new SystemTestCommand(Test_shifter));
	debug_8->WhenPressed(new SystemTestCommand(Test_jugglerLift));
	debug_9->WhileHeld(new SystemTestCommand(Test_elevatorLeft));
	debug_10->WhileHeld(new SystemTestCommand(Test_elevatorRight));
	debug_11->WhileHeld(new SystemTestCommand(Test_trackArm));
	debug_12->WhileHeld(new SystemTestCommand(Test_rearIntake));


}

Joystick* OI::getDriverJoystick()
{
	return 	driverJoystick;
}
Joystick* OI::getOperatorJoystick()
{
	return operatorJoystick;
}
Joystick* OI::getDebugJoystick()
{
	return debugJoystick;
}

Joystick* OI::getDebugJoystick2()
{
	return debugJoystick2;
}




