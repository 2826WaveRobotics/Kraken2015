#include "LoadMagazine.h"
#include "../WaveConstants.h"
#include "SetElevatorPosition.h"
#include "Intake_FrontTote.h"
#include "WaveWait.h"

LoadMagazine::LoadMagazine()
{
	AddSequential(new Intake_FrontTote());
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(highElevatorPosition));
}
