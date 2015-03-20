#ifndef LOAD_MAGAZINE_H
#define LOAD_MAGAZINE_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"
#include "../WaveConstants.h"

class LoadMagazine: public CommandGroup
{
public:
	LoadMagazine(int position = highElevatorPosition);
};

#endif
