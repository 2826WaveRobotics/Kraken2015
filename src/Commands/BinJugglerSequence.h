#ifndef BIN_JUGGLER_SEQUENCE_H
#define BIN_JUGGLER_SEQUENCE_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "WaveConstants.h"
#include "../Subsystems/BinJuggler.h"
#include "WaveWait.h"

class BinJugglerSequence: public CommandGroup
{
public:
	BinJugglerSequence(int configuration);
private:

};

#endif
