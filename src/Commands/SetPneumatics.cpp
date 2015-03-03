#include "SetPneumatics.h"
#include "WaveConstants.h"
#include "Robot.h"

SetPneumatics::SetPneumatics(int cylinder, bool open)
{
	m_cylinder = cylinder;
	m_open = open;
}

// Called just before this Command runs the first time
void SetPneumatics::Initialize()
{
	switch(m_cylinder){
	case cyl_leftHook:
		break;
	case cyl_rightHook:
		break;
	case cyl_hooks:
	{
		int location = Robot::m_binJuggler->getCurrentLocation();
		if(location == Bin_RightActive){
			Robot::m_binJuggler->hookRight(m_open);
		}
		else if(location == Bin_LeftActive){
			Robot::m_binJuggler->hookLeft(m_open);
		}
		//if it is the center, do nothing

		break;
	}
	case cyl_handleHolder:
		Robot::m_recycler->HandleHold(m_open);
		break;
	default:
		break;
	}
}

// Called repeatedly when this Command is scheduled to run
void SetPneumatics::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetPneumatics::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetPneumatics::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetPneumatics::Interrupted()
{

}
