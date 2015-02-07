#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "WaveConstants.h"
#include "tgmath.h"

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
	double GetPIDOutput();
		void UsePIDOutput(double output);
		void InitDefaultCommand();

	void setAbsoluteHeight(double targetHeight);
	void disablePID();

	float getCurrentVoltageOfSensor();
	float convertVoltsToInches (float volts);
	float convertInchesToVolts(double inches);
	double getCurrentHeight();

	//Returns current in Amps.
	float getCurrentFeedback_LeftMotor();
	float getCurrentFeedback_RightMotor();


	// A positive speed will raise the elevator, a negative speed will lower it.
	void setElevatorMotors(float speed);
};

#endif
