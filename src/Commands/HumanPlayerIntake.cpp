#include "HumanPlayerIntake.h"
#include "SetRearIntake.h"

HumanPlayerIntake::HumanPlayerIntake()
{
	AddSequential(new SetRearIntake(1)); // start moving the rear intake
	//
}
