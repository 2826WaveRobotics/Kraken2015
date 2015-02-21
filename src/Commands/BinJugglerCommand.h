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
	BinJugglerCommand(int configuration);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int currentPosition = Bin_LeftConfig;
	int newConfiguration;
	int set;
	int step;
	Timer m_waitTimer;
	Timer m_waitTimer2;
	bool m_sequenceFinished;
};

#endif
