#include "WaitForBin.h"

WaitForBin::WaitForBin()
{
	SetTimeout(5);
}

// Called just before this Command runs the first time
void WaitForBin::Initialize()
{
	//m_startDistance = Robot::m_drive->GetDistanceTraveled();
}

// Called repeatedly when this Command is scheduled to run
void WaitForBin::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForBin::IsFinished()
{
	//double newDistance = Robot::m_drive->GetDistanceTraveled();
	if (!Robot::m_recycler->isBinSensed())
		{
			return true;
		}
		else if(IsTimedOut()){
			return true;
		}
		/*else if(newDistance - m_startDistance > 5){ // should be 4 inches
			return true;
		} */
		else
		{
			//std::cout << "Intake_FrontTote::IsFinished, return false" << std::endl;
			return false;
		}
}

// Called once after isFinished returns true
void WaitForBin::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForBin::Interrupted()
{

}
