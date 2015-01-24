#include "SetDriveDistance.h"
#include "../Robot.h"

SetDriveDistance::SetDriveDistance(double inches)
{
	m_InchesToDrive = inches;

}

void SetDriveDistance::Initialize()
{
	Robot::m_drive->setDistance(m_InchesToDrive);
}


void SetDriveDistance::Execute()
{
	Robot::m_drive->setDriveOutputPID();
}

bool SetDriveDistance::IsFinished()
{
	double distanceTravelled = Robot::m_drive->getCurrentDistance();
	//Stop when we've traveled at least 95% of the requested distance
	//or motor output is less than 5%
	if((distanceTravelled >=  (m_InchesToDrive*0.95))
			|| (fabs(Robot::m_drive->getPIDOutput()) < .05)){
		return true;
	}
	return false;
}

void SetDriveDistance::End()
{
	Robot::m_drive->UsePIDOutput(0);
}

void SetDriveDistance::Interrupted()
{
	End();
}
