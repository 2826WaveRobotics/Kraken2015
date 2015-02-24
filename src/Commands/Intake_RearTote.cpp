#include "Intake_RearTote.h"
#include "../Robot.h"

Intake_RearTote::Intake_RearTote()
{

}

void Intake_RearTote::Initialize()
{
	toteRecieved=false;
}

void Intake_RearTote::Execute()
{
	if	(Robot::m_intake->IsRearSensorTripped())
	{
		Robot::m_intake->SetFrontIntake(-0.75);
		toteRecieved=true;
	}
}

bool Intake_RearTote::IsFinished()
{
	if (!Robot::m_intake->IsRearSensorTripped() && toteRecieved)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Intake_RearTote::End()
{
	Robot::m_intake->SetFrontIntake(0);
}

void Intake_RearTote::Interrupted()
{

}
