#include "RearLoadSequence.h"
#include "RearChamberIntake.h"
#include "SetElevatorPosition.h"
#include "WaveConstants.h"
#include "LoadMagazine.h"

RearLoadSequence::RearLoadSequence()
{
	//Build command sequence here
//	If Elevator is not in High position, set Elevator to High Position

//	Turn on Rear Intake (triggered by user)
	//The tote sensing is now determined by the current draw of the motors
//	When Front Sensor is tripped, turn off Front Intake

//	Set Elevator to Low position
//	Set Elevator to High position
//	Notify User

	//AddSequential(new SetRearIntake(0.5));
	AddParallel(new SetElevatorPosition(highElevatorPosition));
	AddSequential(new RearChamberIntake());
	AddSequential(new LoadMagazine());

}
