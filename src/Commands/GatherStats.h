#ifndef GATHER_STATS_H
#define GATHER_STATS_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Elevator.h"
#include "../Robot.h"
#include "WaveConstants.h"

class GatherStats: public CommandBase
{
public:
	GatherStats();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
