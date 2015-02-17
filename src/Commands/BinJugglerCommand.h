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
	int currentPosition;// = Bin_TightConfig;
	int newConfiguration;
	int set;
	int step;
	Timer m_waitTimer;
	bool m_sequenceFinished;
};

#endif
