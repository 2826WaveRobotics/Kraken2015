#include "AutoDistance.h"
#include "Robot.h"
#include "WaveConstants.h"

AutoDistance::AutoDistance(double distanceToDrive, double maxPower)
{
	m_distanceToDrive = distanceToDrive;
	m_distanceTraveled = 0;
	m_maxPower = maxPower;
}

void AutoDistance::Initialize()
{
	Robot::m_drive->SetPIDMode(mode_distance);
	Robot::m_drive->ResetEncoders(); // reset the encoders so we have a new starting distance
	Robot::m_drive->SetPIDs(1,0,0); // set the PIDs appropriately
	Robot::m_drive->MoveDistance(m_distanceToDrive); // start it moving in that direction
}

void AutoDistance::Execute()
{
	m_distanceTraveled = Robot::m_drive->GetDistanceTraveled();
	Robot::m_drive->DriveDistance(m_maxPower);
	std::cout << "Distance to Drive: " << m_distanceToDrive << "\tDistanceTraveled: "
			<< m_distanceTraveled << "\tMax Power: " << m_maxPower << std::endl;

	m_distanceTraveled = fabs(m_distanceTraveled); // make the distance a positive value
}

bool AutoDistance::IsFinished()
{
	if(m_distanceTraveled > m_distanceToDrive){
		//return true;
	}
	else{
		return false;
	}
}

void AutoDistance::End()
{
	Robot::m_drive->SetPower(-.07); // essentially brake the motors
}

void AutoDistance::Interrupted()
{
	End();
}
