#ifndef SHIFT_H
#define SHIFT_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Shift: public CommandBase
{
public:
	Shift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Solenoid *shifter;

};

#endif
