#include "SetRearIntake.h"
#include "../Robot.h"

SetRearIntake::SetRearIntake(float motorValue)
{
	m_motorValue=motorValue;
}

void SetRearIntake::Initialize()
{
	Robot::m_intake->SetRearIntake(m_motorValue);
}

void SetRearIntake::Execute()
{

}

bool SetRearIntake::IsFinished()
{
	return true;
}

void SetRearIntake::End()
{

}

void SetRearIntake::Interrupted()
{

}
