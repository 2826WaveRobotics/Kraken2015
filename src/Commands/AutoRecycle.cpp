#include "AutoRecycle.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "WaveConstants.h"
#include "WaitForSensor.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

AutoRecycle::AutoRecycle(int position, int hooks)
{
	//wait for the bin before doing anything else
	//AddSequential(new WaitForSensor(dio_bin, 15));
	AddSequential(new WaveWait(.1));
	AddSequential(new SetPneumatics(cyl_handleHolder, close));
	AddParallel(new SetPneumatics(hooks, release));
	AddSequential(new SetRecyclerPosition(up,1, false)); // 100% power up
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(hooks, grab));
	AddSequential(new WaveWait(.1));
	AddParallel(new SetPneumatics(cyl_handleHolder, open));
	//AddSequential(new WaveWait(.01));
	AddParallel(new SetRecyclerPosition(down,-1, false)); //70% power for down
	AddSequential(new WaveWait(.1));
	AddSequential(new BinJugglerCommand(position, false)); // false means auto
}
