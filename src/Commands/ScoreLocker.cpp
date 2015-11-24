#include "ScoreLocker.h"
#include "SetPneumatics.h"
#include "../WaveConstants.h"
#include "SetElevatorPosition.h"
#include "LoadMagazine.h"

ScoreLocker::ScoreLocker()
{
	AddSequential(new LoadMagazine(ScoreElevatorPosition));
	AddSequential(new SetPneumatics(cyl_toteHolder, true));
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	}
