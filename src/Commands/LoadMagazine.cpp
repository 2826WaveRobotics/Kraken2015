#include "LoadMagazine.h"
#include "../WaveConstants.h"
#include "SetElevatorPosition.h"

LoadMagazine::LoadMagazine()
{
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(highElevatorPosition));

}
