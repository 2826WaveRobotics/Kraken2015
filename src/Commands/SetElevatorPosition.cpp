#include "SetElevatorPosition.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"

SetElevatorPosition::SetElevatorPosition(double inches)
{
	m_motorValue = 0;
	m_inches = inches;
}

void SetElevatorPosition::Initialize()
{
	    Robot::m_elevator->setAbsoluteHeight(m_inches);
	    SetTimeout(3.0); //time in seconds
}

void SetElevatorPosition::Execute()
{
	Robot::m_elevator->setElevatorMotors(m_motorValue);
}

bool SetElevatorPosition::IsFinished()
{
	        return false; //always return false because we want the PID to keep the elevator in place
}

void SetElevatorPosition::End()
{
	//Turn the motors off
	Robot::m_elevator->disablePID();
	Robot::m_elevator->setElevatorMotors(0);
}

void SetElevatorPosition::Interrupted()
{
	End();
}
