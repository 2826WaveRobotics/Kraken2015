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
	m_autoBinSensor = RobotMap::autoBinSensor;

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

void Intake::SetControlledIntake()
{
	double power = .65;
	//A-X-Y-B
	bool _A = Robot::oi->getDriverJoystick()->GetRawButton(1); // left in
	bool _X = Robot::oi->getDriverJoystick()->GetRawButton(3); // left out
	bool _Y = Robot::oi->getDriverJoystick()->GetRawButton(4); // right out
	bool _B = Robot::oi->getDriverJoystick()->GetRawButton(2); // right in

	if(_A && _B){ // both in
		SetFrontIntake(power);
	}
	else if(_X && _Y){ // both out
		SetFrontIntake(-power);
	}
	else if(_A && _Y){ // sides are moving differently, and turning a tote
		m_frontIntakeLeft->Set(-power);
		m_frontIntakeRight->Set(-power);
	}
	else if(_X && _B){ // sides are moving differently, and turning a tote
		m_frontIntakeLeft->Set(power);
		m_frontIntakeRight->Set(power);
	}
	else{ // none of our specific conditions were met, we go with the default
		if(_A){
			m_frontIntakeLeft->Set(-power);
		}
		if(_X){
			m_frontIntakeLeft->Set(power);
		}
		if(_Y){
			m_frontIntakeRight->Set(-power);
		}
		if(_B){
			m_frontIntakeRight->Set(power);
		}
	}
}
double Intake::GetLeftCurrent(){
	return m_frontIntakeLeft->GetOutputCurrent();
}
double Intake::GetRightCurrent(){
	return m_frontIntakeRight->GetOutputCurrent();
}
double Intake::GetAverageCurrent(){
	return (GetLeftCurrent() + GetRightCurrent()) / 2;
}


void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
bool Intake::GetBinSensor(){
	return m_autoBinSensor->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

