#include "SetElevatorPosition.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"

SetElevatorPosition::SetElevatorPosition(double inches)
{
	m_motorValue = 0;
	m_inches = inches;
}

void SetElevatorPosition::Initialize()
{
	float currentVolts = Robot::m_elevator->getCurrentVoltage();
	float currentHeight = Robot::m_elevator->convertVoltsToInches(currentVolts);
	if(currentHeight < m_inches)
	{
		//this means the elevator is lower then the target, the elevator needs to go up.
		m_motorValue = .5;
	}
	else
	{
		//this means the elevator is above the target, the elevator needs to go down
		m_motorValue = -.5;
	}
}

void SetElevatorPosition::Execute()
{
	Robot::m_elevator->setElevatorMotors(m_motorValue);
}

bool SetElevatorPosition::IsFinished()
{
	float height = Robot::m_elevator->convertVoltsToInches(Robot::m_elevator->getCurrentVoltage());

	if((m_motorValue > 0) && (height >= m_inches))
	{
		//If the elevator is moving up and is higher than or equal to m_inches, stop the motors
		return true;
	}
	else if((m_motorValue < 0) && (height <= m_inches))
	{
		//If the elevator is moving down and is lower than or equal to m_inches, stop the motors
		return true;
	}
	else
	{
		//We haven't reached m_inches yet, so keep going.
		return false;
	}
}

void SetElevatorPosition::End()
{
	//Turn the motors off
	Robot::m_elevator->setElevatorMotors(0);
}

void SetElevatorPosition::Interrupted()
{
	End();
}
