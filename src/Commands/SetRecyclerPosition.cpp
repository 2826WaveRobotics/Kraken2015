#include "SetRecyclerPosition.h"
#include "../Robot.h"

SetRecyclerPosition::SetRecyclerPosition(bool setUp)
{
	m_setUp = setUp;
	m_speed = 0;
	SetTimeout(2);
}

void SetRecyclerPosition::Initialize()
{
	m_over25 = false;
}

void SetRecyclerPosition::Execute()
{

	if(m_setUp == true){
		m_speed = 1;
	}
	else{
		m_speed = -.85;
	}
	Robot::m_recycler->SetRecycleMotors(m_speed);
}

bool SetRecyclerPosition::IsFinished()
{
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
	m_speed = 0;
	Robot::m_recycler->SetRecycleMotors(m_speed);
	std::cout << "speed stopped" << Robot::m_recycler->isLowerSensorTripped() << std::endl;
}

void SetRecyclerPosition::Interrupted()
{
	End();
}
