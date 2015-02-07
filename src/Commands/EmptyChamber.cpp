#include "EmptyChamber.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"
#include "../WaveConstants.h"



EmptyChamber::EmptyChamber()
{
	m_motorValue = 0;
	m_inches = lowElevatorPosition; //to-do, change this to the initial height on robot

}

void EmptyChamber::Initialize()
{
	Robot::m_elevator->disablePID(); //Disable the PID in order to restart it with setAbsoluteHeight()
	Robot::m_elevator->setAbsoluteHeight(highElevatorPosition);
	SetTimeout(3.0); //time in seconds
}

void EmptyChamber::Execute()
{
	Robot::m_elevator->UsePIDOutput(Robot::m_elevator->GetPIDOutput());
}

bool EmptyChamber::IsFinished()
{
	double currentHeight = Robot::m_elevator->getCurrentHeight();

	if(fabs(currentHeight - highElevatorPosition) < elevatorTolerance) //if we're within an inch of where we want to be
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EmptyChamber::End()
{
	//Do Nothing. Note that the PID is still running when this command ends
}

void EmptyChamber::Interrupted()
{
	End();
}
