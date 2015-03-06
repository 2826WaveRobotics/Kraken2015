#include "RearChamberIntake.h"
#include "Robot.h"

RearChamberIntake::RearChamberIntake()
{
	m_rearSensorHasBeenTripped = false;
	m_frontSensorHasBeenTripped = false;
}

void RearChamberIntake::Initialize()
{
	Robot::m_intake->SetRearIntake(0.75);//Turn motors to intake direction
}

void RearChamberIntake::Execute()
{
	/*if(Robot::m_intake->IsRearSensorTripped()){ // No rear sensor
		m_rearSensorHasBeenTripped = true;
		Robot::m_intake->SetRearIntake(0);
		Robot::m_intake->SetFrontIntake(-.75);
	}*/

	if(/*m_rearSensorHasBeenTripped && */Robot::m_intake->IsFrontSensorTripped()){
		m_frontSensorHasBeenTripped = true;
		Robot::m_intake->SetFrontIntake(0);

	}

}

bool RearChamberIntake::IsFinished()
{
	if(m_rearSensorHasBeenTripped && m_frontSensorHasBeenTripped){
		return true;
	}
	else{
		return false;
	}
}

void RearChamberIntake::End()
{
	Robot::m_intake->SetRearIntake(0);
	Robot::m_intake->SetFrontIntake(0);//Turn motors off
}

void RearChamberIntake::Interrupted()
{
	End();
}
