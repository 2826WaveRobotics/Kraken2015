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
	bool m_rearSensorHasBeenTripped;
	bool m_frontSensorHasBeenTripped;

};

#endif
