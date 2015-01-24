#include "RearLoadSequence.h"
#include "RearChamberIntake.h"
#include "SetElevatorPosition.h"
#include "EmptyChamber.h"
#include "WaveConstants.h"

RearLoadSequence::RearLoadSequence()
{
	//Build command sequence here
	//AddSequential(new CommandName());

	//empties the chamber, elevator is in high load position
	AddSequential(new EmptyChamber());

	//positions a tote into the chamber
	AddSequential(new RearChamberIntake());

	//Load Sequence: moves elevator down, then moves it up
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(highElevatorPosition));

}
