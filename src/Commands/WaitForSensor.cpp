#include "WaitForSensor.h"
#include "Robot.h"

WaitForSensor::WaitForSensor(int sensor, double timeout)
{
	m_sensor = sensor;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void WaitForSensor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WaitForSensor::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool WaitForSensor::IsFinished()
{
	if(IsTimedOut()){
		return true;
	}
	switch(m_sensor){
	case dio_tote:{
		return Robot::m_intake->IsFrontSensorTripped();
	}
	case dio_bin:{
		return Robot::m_intake->GetBinSensor();
	}
	case dio_recyclerUpper:{
		return Robot::m_recycler->isUpperSensorTripped();
	}
	case dio_recyclerLower:{
		return Robot::m_recycler->isLowerSensorTripped();
	}
	default:{
		return false;
	}
	}
}

// Called once after isFinished returns true
void WaitForSensor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForSensor::Interrupted()
{

}
