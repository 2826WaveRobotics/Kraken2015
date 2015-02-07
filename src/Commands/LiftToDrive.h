#ifndef LIFT_TO_DRIVE_H
#define LIFT_TO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"
#include "WaveConstants.h"

class LiftToDrive: public CommandBase
{
public:
	LiftToDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
