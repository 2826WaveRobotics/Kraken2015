#ifndef RECYCLER_H
#define RECYCLER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Recycler: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* trackArmL;
	Talon* trackArmR;
	DigitalInput* lowerSensor;
	DigitalInput* upperSensor;
	Solenoid* canGrabber;


public:
	Recycler();
	void InitDefaultCommand();
	void canControl(bool grab);
	void SetRecycleMotors(float speed);

	bool isUpperSensorTripped();
	bool isLowerSensorTripped();

};

#endif
