#ifndef FRONTCHAMBERINTAKE_H
#define FRONTCHAMBERINTAKE_H

#include "../CommandBase.h"
#include "WPILib.h"

class FrontChamberIntake: public CommandBase
{
public:
	FrontChamberIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
