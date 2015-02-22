#ifndef SHIFT_H
#define SHIFT_H

#include "Subsystems/Drive.h"
#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotMap.h"

class Shift: public CommandBase
{
public:
	Shift(bool highGear);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Drive* drive;
	bool m_highGear;

};

#endif
