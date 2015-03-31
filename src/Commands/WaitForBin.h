#ifndef WaitForBin_H
#define WaitForBin_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Robot.h"

class WaitForBin: public CommandBase
{
public:
	WaitForBin();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_startDistance;
};

#endif
