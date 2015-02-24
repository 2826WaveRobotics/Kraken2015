#ifndef SET_ELEVATOR_POSITION_H
#define SET_ELEVATOR_POSITION_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetElevatorPosition: public CommandBase
{
public:
	SetElevatorPosition(double volts);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float m_volts;
	double m_motorValue;
};

#endif
