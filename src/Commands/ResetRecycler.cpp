#include "ResetRecycler.h"
#include "../WaveConstants.h"
#include "SetElevatorPosition.h"
#include "Intake_FrontTote.h"
#include "WaveWait.h"
#include "SetRecyclerPosition.h"
#include "SetPneumatics.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

ResetRecycler::ResetRecycler()
{

		AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
		AddSequential(new WaveWait(.025));
		AddSequential(new SetRecyclerPosition(down,-.7)); //  bring down @ 70% power

}
