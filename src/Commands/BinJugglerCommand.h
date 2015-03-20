#ifndef BinJugglerCommand_H
#define BinJugglerCommand_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "WaveConstants.h"
#include "../Subsystems/BinJuggler.h"
#include "WaveWait.h"

class BinJugglerCommand: public CommandBase
{
public:
	BinJugglerCommand(int configuration, bool teleop);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int currentPosition;
	int newConfiguration;
	int set;
	int step;
	Timer m_waitTimer;
	Timer m_waitTimer2;
	bool m_sequenceFinished;

	bool m_teleop; // useful for determining if we need to do things differntly in teleop
};

#endif
