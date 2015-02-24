#ifndef SET_REAR_INTAKE_H
#define SET_REAR_INTAKE_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetRearIntake: public CommandBase
{
public:
	SetRearIntake(float motorValue);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float m_motorValue;
};

#endif
