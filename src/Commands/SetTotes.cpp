#include "SetTotes.h"
#include "Robot.h"

SetTotes::SetTotes(bool relative, float totes)
{
	m_relative = relative;
	m_totes = totes;
}

// Called just before this Command runs the first time
void SetTotes::Initialize()
{
	if(m_relative){
		Robot::m_elevator->SetTotes(true, m_totes / 2); // divide the number by 2 because we are still running
			//every command twice, so incrementing the value of totes by 2. Dividing by 2 fixes this
		}
		else{
			Robot::m_elevator->SetTotes(false, m_totes);
		}
}

// Called repeatedly when this Command is scheduled to run
void SetTotes::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetTotes::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetTotes::End()
{
	std::cout << "We have " << Robot::m_elevator->GetTotes() << " totes in the robot" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetTotes::Interrupted()
{
End();
}
