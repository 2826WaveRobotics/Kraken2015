#include "FrontLoadSequence.h"
#include "FrontChamberIntake.h"
#include "SetElevatorPosition.h"
#include "WaveConstants.h"

FrontLoadSequence::FrontLoadSequence()
{
	//Build command sequence here
	//AddSequential(new CommandName());

	AddSequential(new FrontChamberIntake());

	//Load Sequence
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(highElevatorPosition));

}
