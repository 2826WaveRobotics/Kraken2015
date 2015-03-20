#ifndef REARCHAMBERINTAKE_H
#define REARCHAMBERINTAKE_H

#include "../CommandBase.h"
#include "WPILib.h"


// Be sure to verify that the chamber is empty before running this
// command - ie. call LoadMagazine before calling this
class RearChamberIntake: public CommandBase
{
public:
	RearChamberIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_leftIntakeLoad;
	double m_rightIntakeLoad;
	double m_averageIntakeLoad;
	bool m_intakeAtSpeed;
	bool m_intakeWheelsHaveBeenTripped;
	bool m_frontSensorHasBeenTripped;
	bool m_timerTripped;
	bool m_canStop;

	Timer frontIntakeTimer;
	Timer atSpeedTimer;

};

#endif
