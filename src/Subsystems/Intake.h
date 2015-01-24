#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* m_frontIntake;
	Talon* m_rearIntake;
	DigitalInput* m_frontIntakeSensor;
	DigitalInput* m_rearIntakeSensor;
public:
	Intake();
	void InitDefaultCommand();
	void SetFrontIntake(float percentage);
	void SetRearIntake(float percentage);
	bool IsFrontSensorTripped();
	bool IsRearSensorTripped ();
};

#endif
