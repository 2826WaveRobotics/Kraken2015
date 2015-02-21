#ifndef SHIFT_HIGH_H
#define SHIFT_HIGH_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftHigh: public CommandBase
{
public:
	ShiftHigh();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_shiftState = false;
};

#endif
