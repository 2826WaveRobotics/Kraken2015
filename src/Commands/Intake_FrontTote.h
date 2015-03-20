#ifndef INTAKE_FRONT_TOTE_H
#define INTAKE_FRONT_TOTE_H

#include "../CommandBase.h"
#include "WPILib.h"

class Intake_FrontTote: public CommandBase
{
public:
	Intake_FrontTote(double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_power;
};

#endif
