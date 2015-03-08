#include "Intake.h"
#include "../RobotMap.h"
#include "../Robot.h"

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
void Intake::SetControlledIntake()
{
	//A-X-Y-B
	bool _A = Robot::oi->getDriverJoystick()->GetRawButton(1); // left in
	bool _X = Robot::oi->getDriverJoystick()->GetRawButton(3); // left out
	bool _Y = Robot::oi->getDriverJoystick()->GetRawButton(4); // right out
	bool _B = Robot::oi->getDriverJoystick()->GetRawButton(2); // right in

	if(_A && _B){ // both in
		SetFrontIntake(.5);
	}
	else if(_X && _Y){ // both out
		SetFrontIntake(-.5);
	}
	else if(_A && _Y){ // sides are moving differently, and turning a tote
		m_frontIntakeLeft->Set(-.5);
		m_frontIntakeRight->Set(-.5);
	}
	else if(_X && _B){ // sides are moving differently, and turning a tote
		m_frontIntakeLeft->Set(.5);
		m_frontIntakeRight->Set(.5);
	}
	else{ // none of our specific conditions were met, we go with the default
		if(_A){
			m_frontIntakeLeft->Set(-.5);
		}
		if(_X){
			m_frontIntakeLeft->Set(.5);
		}
		if(_Y){
			m_frontIntakeRight->Set(-.5);
		}
		if(_B){
			m_frontIntakeRight->Set(.5);
		}
	}
}
void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

