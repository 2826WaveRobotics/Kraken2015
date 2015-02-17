#include "OI.h"
#include "Robot.h"
#include "Commands/BinJugglerCommand.h"

OI::OI()
{
	driverJoystick = new Joystick(0);
	operatorJoystick = new Joystick(1);
	debugJoystick = new Joystick(2);
	debugJoystick2 = new Joystick(3);

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
void OI::checkInput(){

	bool param = getDriverJoystick()->GetRawAxis(3)>0.75 ? true : false; // shift with the trigger
	Robot::m_drive->ShiftGear(param);
	Robot::m_drive->DriveWithJoysticks(driverJoystick->GetRawAxis(1), getDriverJoystick()->GetRawAxis(4));
	Robot::m_elevator->setElevatorMotors(operatorJoystick->GetRawAxis(1));
	Robot::m_recycler->SetRecycleMotors(operatorJoystick->GetRawAxis(5));

	operatorJoystick->GetRawAxis(2) < .55 ? Robot::m_intake->SetFrontIntake(0) : Robot::m_intake->SetFrontIntake(operatorJoystick->GetRawAxis(2));
	operatorJoystick->GetRawAxis(3) < .55 ? Robot::m_intake->SetRearIntake(0) : Robot::m_intake->SetRearIntake(operatorJoystick->GetRawAxis(3));

	if(debug_1->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
	}
	if(debug_2->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LeftHook, On);
	}
	if(debug_3->Get()){
		Robot::m_binJuggler->loadSelection(Bin_RightHook, On);
	}
	if(debug_4->Get()){
		Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
	}
	if(debug_5->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LeftLock, Off);
	}
	if(debug_6->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LeftHook, Off);
	}
	if(debug_7->Get()){
		Robot::m_binJuggler->loadSelection(Bin_RightHook, Off);
	}
	if(debug_8->Get()){
		Robot::m_binJuggler->loadSelection(Bin_RightLock, Off);
	}
	if(debug_9->Get() || debug_10->Get() || debug_13->Get() || debug_14->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
	}
	if(debug_11->Get() || debug_12->Get() || debug_15->Get() || debug_16->Get()){
		Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
	}

	operator_A->WhenPressed(new BinJugglerCommand(Bin_CenterConfig));
	operator_X->WhenPressed(new BinJugglerCommand(Bin_LeftConfig));
	operator_B->WhenPressed(new BinJugglerCommand(Bin_RightConfig));

}



