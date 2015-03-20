#include "SetFrontIntake.h"
#include "Robot.h"

SetFrontIntake::SetFrontIntake(double power, double timeout)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	m_power = power;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void SetFrontIntake::Initialize()
{
	Robot::m_intake->SetFrontIntake(m_power);
	SetTimeout(m_timeout);
}

// Called repeatedly when this Command is scheduled to run
void SetFrontIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetFrontIntake::IsFinished()
{
	if(IsTimedOut()){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void SetFrontIntake::End()
{
	Robot::m_intake->SetFrontIntake(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetFrontIntake::Interrupted()
{

}
