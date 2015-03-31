#include "AcquireBins.h"
#include "WaveConstants.h"
#include "SetRecyclerPosition.h"
#include "SetPneumatics.h"
#include "WaveWait.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

AcquireBins::AcquireBins()
{
	AddSequential(new SetPneumatics(cyl_hooks, release));
	AddSequential(new SetRecyclerPosition(up,1)); // bring up the recycle bin [100% power up]
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // open the appropriate hook
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the recycle bin from the track
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(down,-.7)); //.7 speed down
}
