#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() :
Subsystem("Intake")
{
	m_frontIntakeLeft = RobotMap ::frontIntakeLeft;
	m_frontIntakeRight = RobotMap ::frontIntakeRight;
	m_rearIntake = RobotMap::rearIntake;
	m_frontIntakeSensor = RobotMap::frontIntakeSensor;
	m_rearIntakeSensor = RobotMap::rearIntakeSensor;
}

void Intake::SetFrontIntake(float percentage)
{
	m_frontIntakeLeft->Set(percentage);
	m_frontIntakeRight->Set(-percentage);
}

void Intake::SetRearIntake(float percentage)
{
	m_rearIntake->Set(-percentage);
}

bool Intake::IsFrontSensorTripped()
{
	if(m_frontIntakeSensor->Get()==true) {
		return true;
	}
	else {
		return false;
	}
}

bool Intake:: IsRearSensorTripped()
{
	if(m_rearIntakeSensor->Get()==true) {
		return true;
	}
	else {
		return false;
	}
}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

