#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "WaveConstants.h"
#include "tgmath.h"

class Elevator: public PIDSubsystem
{
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
	void lockTotes(bool lock);
	void toggleLockTotes();

	double checkSoftStops(double desiredOutput, bool invertedOutput = false);
	void CalculatePIDs();
	void CalculateTotes();
	void SetTotes(bool relative, float totes);
	float GetTotes();
	double GetSpeed();

	void SetPIDs(double p, double i, double d);
	bool IsSensorValid();

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_elevatorLeft;
	CANTalon* m_elevatorRight;
	AnalogInput* m_elevatorSensor;
	Solenoid* m_toteLock;
	Timer elevatorClock;

	double m_previousCurrentOfElevator;
	float m_numOfTotes;
	bool m_haveBin;

	double m_upP;
	double m_downP;
	double m_upI;
	double m_downI;
	double m_upD;
	double m_downD;

};

#endif
