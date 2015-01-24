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
	Robot::m_elevator->disablePID(); //Disable the PID in order to restart it with setAbsoluteHeight()
	Robot::m_elevator->setAbsoluteHeight(m_inches);
	SetTimeout(3.0); //time in seconds
}

void SetElevatorPosition::Execute()
{
	Robot::m_elevator->UsePIDOutput(Robot::m_elevator->GetPIDOutput());
}

bool SetElevatorPosition::IsFinished()
{
	double currentHeight = Robot::m_elevator->getCurrentHeight();

	if(fabs(currentHeight - m_inches) < 1) //if we're within an inch of where we want to be
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SetElevatorPosition::End()
{
	//Do Nothing. Note that the PID is still running when this command ends
}

void SetElevatorPosition::Interrupted()
{
	End();
}
