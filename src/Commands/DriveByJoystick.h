#ifndef DRIVE_BY_JOYSTICK_H
#define DRIVE_BY_JOYSTICK_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveByJoystick: public CommandBase
{
public:
	DriveByJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
