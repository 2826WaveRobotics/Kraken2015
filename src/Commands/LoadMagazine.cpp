#include "LoadMagazine.h"
#include "SetElevatorPosition.h"
#include "Intake_FrontTote.h"
#include "WaveWait.h"
#include "Robot.h"
#include "SetTotes.h"

LoadMagazine::LoadMagazine(int position)
{
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(position));
	AddSequential(new SetTotes(true, 1));
}


