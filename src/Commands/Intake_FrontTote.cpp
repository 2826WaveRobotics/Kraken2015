#include "Intake_FrontTote.h"
#include "../Robot.h"

Intake_FrontTote::Intake_FrontTote()
{

}

void Intake_FrontTote::Initialize()
{
	Robot::m_intake->SetFrontIntake(0.75);
}

void Intake_FrontTote::Execute()
{

}

bool Intake_FrontTote::IsFinished()
{
	if (Robot::m_intake->IsFrontSensorTripped())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Intake_FrontTote::End()
{
	Robot::m_intake->SetFrontIntake(0);
}

void Intake_FrontTote::Interrupted()
{
	End();
}
