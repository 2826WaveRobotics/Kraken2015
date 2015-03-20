#ifndef SetFrontIntake_H
#define SetFrontIntake_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetFrontIntake: public CommandBase
{
public:
	SetFrontIntake(double power, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_power;
	double m_timeout;
};

#endif
