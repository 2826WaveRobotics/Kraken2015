#include "OI.h"
#include "Robot.h"
#include "Commands/BinJugglerCommand.h"
#include "Commands/Shift.h"
#include "Commands/ShiftHigh.h"

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

	operator_A = new JoystickButton(operatorJoystick, 1);
	operator_B = new JoystickButton(operatorJoystick, 2);
	operator_X = new JoystickButton(operatorJoystick, 3);
	operator_Y = new JoystickButton(operatorJoystick, 4);
	operator_LB = new JoystickButton(operatorJoystick, 5);
	operator_RB = new JoystickButton(operatorJoystick, 6);
	operator_Back = new JoystickButton(operatorJoystick, 7);
	operator_Start = new JoystickButton(operatorJoystick, 8);
	operator_LJoy = new JoystickButton(operatorJoystick, 9);
	operator_RJoy = new JoystickButton(operatorJoystick, 10);

	operator_Y->WhenPressed(new ShiftHigh);
	operator_A->WhenPressed(new BinJugglerCommand(Bin_CenterConfig)); // NOT WORKING
//	operator_X->WhenPressed(new BinJugglerCommand(Bin_LeftConfig));
//	operator_B->WhenPressed(new BinJugglerCommand(Bin_RightConfig));

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
	Robot::m_drive->DriveWithJoysticks(driverJoystick->GetRawAxis(1), driverJoystick->GetRawAxis(4));

	Robot::m_elevator->setElevatorMotors(operatorJoystick->GetRawAxis(1));

	operatorJoystick->GetRawAxis(2) < .05 ? Robot::m_intake->SetFrontIntake(0) : Robot::m_intake->SetFrontIntake(operatorJoystick->GetRawAxis(2));
	operatorJoystick->GetRawAxis(3) < .05 ? Robot::m_intake->SetRearIntake(0) : Robot::m_intake->SetRearIntake(operatorJoystick->GetRawAxis(3));

	if(GetDebugJoystickButton(1)){
		Robot::m_binJuggler->loadSelection(Bin_LeftLock, true);
	}
	if(GetDebugJoystickButton(2)){
		Robot::m_binJuggler->loadSelection(Bin_LeftHook, true);
	}
	if(GetDebugJoystickButton(3)){
		Robot::m_binJuggler->loadSelection(Bin_RightHook, true);
	}
	if(GetDebugJoystickButton(4)){
		Robot::m_binJuggler->loadSelection(Bin_RightLock, true);
	}
	if(GetDebugJoystickButton(5)){
		Robot::m_binJuggler->loadSelection(Bin_LeftLock, false);
	}
	if(GetDebugJoystickButton(6)){
		Robot::m_binJuggler->loadSelection(Bin_LeftHook, false);
	}
	if(GetDebugJoystickButton(7)){
		Robot::m_binJuggler->loadSelection(Bin_RightHook, false);
	}
	if(GetDebugJoystickButton(8)){
		Robot::m_binJuggler->loadSelection(Bin_RightLock, false);
	}
	if(GetDebugJoystickButton(9)){
		Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, true);
	}
	if(GetDebugJoystickButton(10)){

	}
	if(GetDebugJoystickButton(11)){

	}
	if(GetDebugJoystickButton(12)){

	}
	if(GetDebugJoystickButton(13)){
		Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, false);
	}
	if(GetDebugJoystickButton(14)){

	}
	if(GetDebugJoystickButton(15)){

	}
	if(GetDebugJoystickButton(16)){

	}

	if((Robot::m_recycler->isLowerSensorTripped() == true) && (Robot::m_recycler->isUpperSensorTripped() == true)){ // neither sensor tripped
		Robot::m_recycler->SetRecycleMotors(operatorJoystick->GetRawAxis(5));
	}
	else if((Robot::m_recycler->isLowerSensorTripped() == false) && (operatorJoystick->GetRawAxis(5) > 0)){ // lower is tripped, but we're going up
		Robot::m_recycler->SetRecycleMotors(operatorJoystick->GetRawAxis(5));
	}
	else if((Robot::m_recycler->isUpperSensorTripped() == false) && (operatorJoystick->GetRawAxis(5) < 0)){ // upper is tripped, but we're going down
		Robot::m_recycler->SetRecycleMotors(operatorJoystick->GetRawAxis(5));
	}
	else{
		std::cout << "CANNOT MOVE THE RECYCLER ANY MORE" << std::endl;
		Robot::m_recycler->SetRecycleMotors(0);
	}





	if(driverJoystick->GetRawButton(7)){ // BREAKS THE PROGRAM
		Robot::m_elevator->lockTotes(true);
	}
	if(driverJoystick->GetRawButton(8)){
		Robot::m_elevator->lockTotes(false);
	}


}

bool OI::GetDebugJoystickButton(int number){
	switch(number){
	case 1:
		return debugJoystick2->GetRawButton(1);
		break;
	case 2:
		return debugJoystick2->GetRawButton(2);
		break;
	case 3:
		return debugJoystick2->GetRawButton(3);
		break;
	case 4:
		return debugJoystick2->GetRawButton(4);
		break;
	case 5:
		return debugJoystick->GetRawButton(9);
		break;
	case 6:
		return debugJoystick->GetRawButton(10);
		break;
	case 7:
		return debugJoystick->GetRawButton(11);
		break;
	case 8:
		return debugJoystick->GetRawButton(12);
		break;
	case 9:
		return debugJoystick->GetRawButton(5);
		break;
	case 10:
		return debugJoystick->GetRawButton(6);
		break;
	case 11:
		return debugJoystick->GetRawButton(7);
		break;
	case 12:
		return debugJoystick->GetRawButton(8);
		break;
	case 13:
		return debugJoystick->GetRawButton(1);
		break;
	case 14:
		return debugJoystick->GetRawButton(2);
		break;
	case 15:
		return debugJoystick->GetRawButton(3);
		break;
	case 16:
		return debugJoystick->GetRawButton(4);
		break;
	default:
		return false;
		break;
	}
}


