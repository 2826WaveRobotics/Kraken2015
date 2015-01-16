#ifndef SHIFT_LOW_H
#define SHIFT_LOW_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftLow: public CommandBase
{
public:
	ShiftLow();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
