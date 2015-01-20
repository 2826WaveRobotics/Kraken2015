#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_elevatorLeft;
	CANTalon* m_elevatorRight;
	AnalogInput* m_elevatorSensor;


public:
	Elevator();
	void InitDefaultCommand();
	float getCurrentVoltage();
	float convertVoltsToInches (float volts);

	// A positive speed will raise the elevator, a negative speed will lower it.
	void setElevatorMotors(float speed);
};

#endif
