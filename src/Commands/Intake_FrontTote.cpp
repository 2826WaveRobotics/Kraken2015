#include "Intake_FrontTote.h"
#include "../Robot.h"

Intake_FrontTote::Intake_FrontTote()
{

}

void Intake_FrontTote::Initialize()
{
	Robot::m_intake->UseIntakeSystem(true);
	Robot::m_intake->SetFrontIntake(0.75);
}

void Intake_FrontTote::Execute()
{
	Robot::m_intake->SetFrontIntake(-0.75);

}

bool Intake_FrontTote::IsFinished()
{
	if (Robot::m_intake->IsFrontSensorTripped())
	{
		std::cout << "Intake_FrontTote::IsFinished, return true" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Intake_FrontTote::IsFinished, return false" << std::endl;
		return false;
	}
}

void Intake_FrontTote::End()
{
	//Robot::m_intake->SetFrontIntake(0);
	//Robot::m_intake->UseIntakeSystem(false);
}

void Intake_FrontTote::Interrupted()
{
	End();
}