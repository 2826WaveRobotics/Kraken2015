#include "KillDriveStraight.h"
#include "../Robot.h"

KillDriveStraight::KillDriveStraight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void KillDriveStraight::Initialize()
{
	Robot::m_drive->DisablePID();
	Robot::m_drive->DriveStraight(0);
}

// Called repeatedly when this Command is scheduled to run
void KillDriveStraight::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool KillDriveStraight::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void KillDriveStraight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KillDriveStraight::Interrupted()
{

}
