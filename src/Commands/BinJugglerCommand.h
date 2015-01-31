#ifndef BIN_JUGGLER_COMMAND_H
#define BIN_JUGGLER_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/BinJuggler.h"
#include "../Robot.h"

class BinJugglerCommand: public CommandBase
{
public:
	BinJugglerCommand(int cylinder, bool state);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int m_cylinder;
	bool m_state;

};

#endif
