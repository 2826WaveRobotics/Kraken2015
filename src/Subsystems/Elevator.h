#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Elevator: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_elevatorLeft;
	CANTalon* m_elevatorRight;
	AnalogInput* m_elevatorSensor;


public:
	Elevator();

	double ReturnPIDInput();
		void UsePIDOutput(double output);
		void InitDefaultCommand();

	void setAbsoluteHeight(double targetHeight);
	void disablePID();

	float getCurrentVoltage();
	float convertVoltsToInches (float volts);
	float convertInchesToVolts(double inches);


	// A positive speed will raise the elevator, a negative speed will lower it.
	void setElevatorMotors(float speed);
};

#endif
