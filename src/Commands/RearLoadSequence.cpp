#include "RearLoadSequence.h"
#include "RearChamberIntake.h"
#include "SetElevatorPosition.h"
#include "WaveConstants.h"
#include "SetRearIntake.h"

RearLoadSequence::RearLoadSequence()
{
	//Build command sequence here
//	If Elevator is not in High position, set Elevator to High Position
//	Turn on Rear Intake (triggered by user)
//	When Rear Sensor is tripped, outtake Front Intake
//	When Rear Sensor turns off, intake Front Intake
//	When Front Sensor is tripped, turn off Front Intake
//	Set Elevator to Low position
//	Set Elevator to High position
//	Notify User
	//AddSequential(new CommandName());

	AddSequential(new SetRearIntake(0.5));
	AddParallel(new SetElevatorPosition(highElevatorPosition));

	//positions a tote into the chamber
	AddSequential(new RearChamberIntake());

	//Load Sequence: moves elevator down, then moves it up
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(highElevatorPosition));


}
