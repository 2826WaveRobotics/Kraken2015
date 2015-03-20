#include "RearChamberIntake.h"
#include "Robot.h"

RearChamberIntake::RearChamberIntake()
{

}

void RearChamberIntake::Initialize()
{
	Robot::m_intake->UseIntakeSystem(true);

	Robot::m_intake->SetFrontIntake(-.5);
	frontIntakeTimer.Reset();
	frontIntakeTimer.Stop(); // just to initialize the sensor
	atSpeedTimer.Reset();
	atSpeedTimer.Start(); // begin counting how long the command has been running

	m_intakeAtSpeed = false;
	m_intakeWheelsHaveBeenTripped = false;
	m_frontSensorHasBeenTripped = false;
	m_timerTripped = false;
	m_canStop = false;
}

void RearChamberIntake::Execute()
{
	m_averageIntakeLoad = Robot::m_intake->GetAverageCurrent();

	if(atSpeedTimer.HasPeriodPassed(1)){ // wait 1 second for the motors to get up to speed
		m_intakeAtSpeed = true;
	}

	if(m_intakeAtSpeed && m_averageIntakeLoad > 5){ // some value of load for motor (5 amps with bane bots wheels)
		m_intakeWheelsHaveBeenTripped = true;
	}

	if(m_intakeWheelsHaveBeenTripped){ // we hit the wheels, go backwards in a second or so
		frontIntakeTimer.Reset();
		frontIntakeTimer.Start();
	}

	if(frontIntakeTimer.HasPeriodPassed(.5)){ // .5 seconds of spitting out before pulling back
		Robot::m_intake->SetFrontIntake(.75);
		m_timerTripped = true;
	}

	if(m_timerTripped && m_frontSensorHasBeenTripped){ // we have now tripped the front sensor
		m_canStop = true;
	}

}

bool RearChamberIntake::IsFinished()
{
	if(m_canStop){
		return true;
	}
	else{
		return false;
	}
}

void RearChamberIntake::End()
{
	Robot::m_intake->SetFrontIntake(0);//Turn motors off
	Robot::m_intake->UseIntakeSystem(false);
}

void RearChamberIntake::Interrupted()
{

}
