#include "AutoRecycle.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "WaveConstants.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

AutoRecycle::AutoRecycle(int position)
{
	AddSequential(new SetPneumatics(cyl_handleHolder, close));
	AddParallel(new SetPneumatics(cyl_hooks, release));
	AddSequential(new SetRecyclerPosition(up));
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(cyl_hooks, grab));
	AddSequential(new WaveWait(.1));
	AddParallel(new SetPneumatics(cyl_handleHolder, open));
	AddSequential(new SetRecyclerPosition(down));
	AddParallel(new BinJugglerCommand(position));
}
