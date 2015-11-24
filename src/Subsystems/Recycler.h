#ifndef RECYCLER_H
#define RECYCLER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Recycler: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* trackArmLeft;
	CANTalon* trackArmRight;
	DigitalInput* binLowerSensor;
	DigitalInput* binUpperSensor;
	Solenoid* handleHolder;
	DigitalInput* m_binSensor;

	bool m_resourceFree;

public:
	Recycler();
	void InitDefaultCommand();
	void canControl(bool grab);
	double GetCurrent();
	void SetRecycleMotors(float speed);

	bool isUpperSensorTripped();
	bool isLowerSensorTripped();

	void HandleHold(bool open);
	void ToggleHandleHolder();

	bool isBinSensed();

	//Locking the resource will prevent two command instances from
	//moving the recycler at the same time.
	void LockResource();
	void UnlockResource();
	bool IsResourceLocked(){ return !m_resourceFree; };
};

#endif
