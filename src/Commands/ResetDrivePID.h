#ifndef ResetDrivePID_H
#define ResetDrivePID_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetDrivePID: public CommandBase
{
public:
	ResetDrivePID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
