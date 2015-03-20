#include "ResetDrivePID.h"
#include "Robot.h"

ResetDrivePID::ResetDrivePID()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ResetDrivePID::Initialize()
{
	Robot::m_drive->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void ResetDrivePID::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ResetDrivePID::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ResetDrivePID::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetDrivePID::Interrupted()
{

}
