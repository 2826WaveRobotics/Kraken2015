#include "LiftToDrive.h"

LiftToDrive::LiftToDrive()
{

}

void LiftToDrive::Initialize()
{
		Robot::m_elevator->disablePID(); //Disable the PID in order to restart it with setAbsoluteHeight()
		Robot::m_elevator->setAbsoluteHeight(bumpHeight);
		SetTimeout(3.0); //time in seconds
}

void LiftToDrive::Execute()
{
	Robot::m_elevator->UsePIDOutput(Robot::m_elevator->GetPIDOutput());
}

bool LiftToDrive::IsFinished()
{
	double currentHeight = Robot::m_elevator->getCurrentHeight();

		if(fabs(currentHeight - bumpHeight) < elevatorTolerance) //if we're within an inch of where we want to be
		{
			return true;
		}
		else
		{
			return false;
		}
}

void LiftToDrive::End()
{

}

void LiftToDrive::Interrupted()
{
	End();
}
