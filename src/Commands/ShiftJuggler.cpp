#include "ShiftJuggler.h"
#include "SetPneumatics.h"
#include "WaveWait.h"
#include "../WaveConstants.h"
#include "BinJugglerCommand.h"
#include "LoadMagazine.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

ShiftJuggler::ShiftJuggler()
{
	std::cout << "Shift Juggler Running" << std::endl;
	AddSequential(new SetPneumatics(cyl_hooks, open));
	AddParallel(new LoadMagazine(highElevatorPosition));//elevator down then up
	//AddSequential(new WaveWait(.25));
	if(close){
		AddSequential(new WaveWait(5));
	}
	AddSequential(new BinJugglerCommand(Bin_CenterActive,true)); // true means teleop
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_leftHook, close));
	AddSequential(new SetPneumatics(cyl_rightHook, close));
}
