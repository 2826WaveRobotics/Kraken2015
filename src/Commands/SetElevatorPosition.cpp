#include "SetElevatorPosition.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"

SetElevatorPosition::SetElevatorPosition(double inches)
{
	Requires(Robot::m_elevator);
	m_motorValue = 0;
	m_inches = inches;
}

void SetElevatorPosition::Initialize()
{
	Robot::m_elevator->disablePID(); //Disable the PID in order to restart it with setAbsoluteHeight()
	Robot::m_elevator->setAbsoluteHeight(m_inches); //enables PID after setting new value
	SetTimeout(2.0); //time in seconds
}

void SetElevatorPosition::Execute()
{
	Robot::m_elevator->UsePIDOutput(Robot::m_elevator->GetPIDOutput());
}

bool SetElevatorPosition::IsFinished()
{
	double currentHeight = Robot::m_elevator->convertVoltsToInches(Robot::m_elevator->getCurrentVoltageOfSensor());

	//std::cout << "SetElevatorPosition::IsFinished: currentHeight == " << currentHeight << "  m_volts=" << m_volts << std::endl;
	if(fabs(currentHeight - m_inches) < elevatorTolerance) //if we're within an .1*inch of where we want to be
	{
		return true;
	}
	else if (IsTimedOut())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SetElevatorPosition::End()
{
	//std::cout << "setElevatorPosition::End" << std::endl;
	//Do Nothing. Note that the PID is still running when this command ends
}

void SetElevatorPosition::Interrupted()
{
	End();
}
