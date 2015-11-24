#include "SetRecyclerPosition.h"
#include "../Robot.h"

SetRecyclerPosition::SetRecyclerPosition(bool setUp, double speed, bool getLock)
{
	m_setUp = setUp;
	m_speed = speed;
	SetTimeout(3);
	m_getLock = getLock;
}

void SetRecyclerPosition::Initialize()
{

}

void SetRecyclerPosition::Execute()
{
	if(m_setUp == true){
		//m_speed = 1;
	}
	else{
		//m_speed = -1; // -.85;
	}
	Robot::m_recycler->SetRecycleMotors(m_speed);
	if(m_getLock)
	{
		Robot::m_recycler->LockResource();
	}
}

bool SetRecyclerPosition::IsFinished()
{
	if(Robot::m_recycler->IsResourceLocked() && !m_getLock)
	{
		return true;
	}

	if(m_setUp == true) {
		//	std::cout << "Upper Sensor Tripped?" << Robot::m_recycler->isUpperSensorTripped() << std::endl;
		return Robot::m_recycler->isUpperSensorTripped();
	}
	else{
		//std::cout << "Upper Lower Tripped?" << Robot::m_recycler->isLowerSensorTripped() << std::endl;
		return Robot::m_recycler->isLowerSensorTripped();
	}
	if(IsTimedOut())
	{
		m_speed = 0;
		Robot::m_recycler->SetRecycleMotors(m_speed);
		return true;
	}
}

void SetRecyclerPosition::End()
{
	if(m_getLock)
	{
	    Robot::m_recycler->UnlockResource();
	}
	m_speed = 0;
	Robot::m_recycler->SetRecycleMotors(m_speed);
	std::cout << "speed stopped" << Robot::m_recycler->isLowerSensorTripped() << std::endl;
}

void SetRecyclerPosition::Interrupted()
{
	End();
}
