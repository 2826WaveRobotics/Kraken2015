#ifndef BIN_JUGGLER_SEQUENCE_SHIFT_H
#define BIN_JUGGLER_SEQUENCE_SHIFT_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/BinJuggler.h"
#include "../Robot.h"

class BinJugglerSequenceShift: public CommandBase
{
public:
	BinJugglerSequenceShift(bool forward);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:


};

#endif
