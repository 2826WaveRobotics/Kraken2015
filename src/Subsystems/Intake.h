#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_frontIntakeLeft;
	CANTalon* m_frontIntakeRight;
	CANTalon* m_rearIntake;
	DigitalInput* m_frontIntakeSensor;
	DigitalInput* m_humanWallSensor;
	bool m_intakeSystemInUse;
public:
	Intake();
	void InitDefaultCommand();
	void SetFrontIntake(float percentage);
	void SetRearIntake(float percentage);
	bool IsFrontSensorTripped();
	bool IsAligned ();

	bool IsIntakeSystemInUse();
	void UseIntakeSystem(bool inUse);
};

#endif
