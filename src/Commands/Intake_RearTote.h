#ifndef INTAKE_REAR_TOTE_H
#define INTAKE_REAR_TOTE_H
#include "../CommandBase.h"
#include "WPILib.h"

class Intake_RearTote: public CommandBase
{
public:
	Intake_RearTote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool toteRecieved;
};

#endif
