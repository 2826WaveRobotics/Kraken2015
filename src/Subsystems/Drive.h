#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public PIDSubsystem
{
public:
	Drive();
	void InitDefaultCommand();
	void DriveWithJoysticks(float left, float right);
	void ShiftGear(bool highGear);
private:

};

#endif
