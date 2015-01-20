#include "Elevator.h"
#include "../RobotMap.h"

namespace
{
	double MaxVolts = 12;
	double MinVolts = 0;
	double MinLength = 0;
	double MaxLength = 25;
}




Elevator::Elevator() :
		Subsystem("Elevator")
{
	m_elevatorLeft = RobotMap::elevatorLeft;
	m_elevatorRight = RobotMap::elevatorRight;
	m_elevatorSensor = RobotMap::elevatorSensor;
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float Elevator::convertVoltsToInches (float volts)
{
	double inches = ((MaxVolts - MinVolts)/(MaxLength - MinLength)) * volts;
	return inches;
}

float Elevator::getCurrentVoltage()
{
	return	m_elevatorSensor->GetVoltage();
}

void Elevator::setElevatorMotors(float speed)
{
	m_elevatorLeft->Set(speed);
	m_elevatorRight->Set(-speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

