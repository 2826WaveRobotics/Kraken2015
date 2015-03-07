#include "SetRecyclerPosition.h"
#include "../Robot.h"

SetRecyclerPosition::SetRecyclerPosition(bool setUp)
{
	m_setUp = setUp;
	m_speed = 0;
}

void SetRecyclerPosition::Initialize()
{
	if(m_setUp == true){
		m_speed = .8;
	}
	else{
<<<<<<< HEAD
		m_speed = -.775;
=======
		m_speed = -.65;
>>>>>>> parent of 564e576... FAILED(but its late)
	}
	Robot::m_recycler->SetRecycleMotors(m_speed);
}

void SetRecyclerPosition::Execute()
{

}

bool SetRecyclerPosition::IsFinished()
{
	if(m_setUp == true) {
		std::cout << "Upper Sensor Tripped?" << Robot::m_recycler->isUpperSensorTripped() << std::endl;
		return Robot::m_recycler->isUpperSensorTripped();
	}
	else{
		std::cout << "Upper Lower Tripped?" << Robot::m_recycler->isLowerSensorTripped() << std::endl;
		return Robot::m_recycler->isLowerSensorTripped();
	}
}

void SetRecyclerPosition::End()
{
	m_speed = 0;
	Robot::m_recycler->SetRecycleMotors(m_speed);
}

void SetRecyclerPosition::Interrupted()
{
	End();
}
