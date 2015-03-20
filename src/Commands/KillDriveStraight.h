#ifndef KillDriveStraight_H
#define KillDriveStraight_H

#include "../CommandBase.h"
#include "WPILib.h"

class KillDriveStraight: public CommandBase
{
public:
	KillDriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
