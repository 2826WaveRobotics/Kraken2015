#include "FrontChamberIntake.h"
#include "Robot.h"

FrontChamberIntake::FrontChamberIntake()
{

}

void FrontChamberIntake::Initialize()
{
	Robot::m_intake->SetFrontIntake(0.75);//Turn motors to intake direction
}

void FrontChamberIntake::Execute()
{

}

bool FrontChamberIntake::IsFinished()
{
	return Robot::m_intake->IsFrontSensorTripped();
}

void FrontChamberIntake::End()
{
	Robot::m_intake->SetFrontIntake(0);//Turn motors off
}

void FrontChamberIntake::Interrupted()
{
	End();
}
