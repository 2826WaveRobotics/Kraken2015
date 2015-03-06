#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() :
Subsystem("Intake")
{
	m_frontIntakeLeft = RobotMap ::frontIntakeLeft;
	m_frontIntakeRight = RobotMap ::frontIntakeRight;
	m_rearIntake = RobotMap::rearIntake;
	m_frontIntakeSensor = RobotMap::frontIntakeSensor;
	m_humanWallSensor = RobotMap::humanWallSensor;

	m_intakeSystemInUse = false;
}

bool Intake::IsIntakeSystemInUse()
{
	return m_intakeSystemInUse;
}

void Intake::UseIntakeSystem(bool inUse)
{
	m_intakeSystemInUse=inUse;
}

void Intake::SetFrontIntake(float percentage)
{
	m_frontIntakeLeft->Set(-percentage);
	m_frontIntakeRight->Set(percentage);
}

void Intake::SetRearIntake(float percentage)
{
	m_rearIntake->Set(-percentage);
}

bool Intake::IsFrontSensorTripped()
{
	if(m_frontIntakeSensor->Get()==true) {
		return false;
	}
	else {
		return true;
	}
}

bool Intake::IsAligned()
{
	if(m_humanWallSensor->Get()==true) {
		return false;
	}
	else {
		return true;
	}
}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

