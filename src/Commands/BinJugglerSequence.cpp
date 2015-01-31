#include "BinJugglerSequence.h"
#include "BinJugglerCommand.h"

BinJugglerSequence::BinJugglerSequence(int configuration) {
	//Build command sequence here
	//AddSequential(new CommandName());


//	AddSequential(new BinJugglerCommand(0, 0));

		switch(configuration)
	{
		case Bin_CenterConfig:
			AddSequential(new BinJugglerCommand(Bin_LiftCylinder, On));
			AddSequential(new WaveWait(0.5));
			AddSequential(new BinJugglerCommand(Bin_LeftLock, On));
			AddSequential(new BinJugglerCommand(Bin_RightLock, On));
			break;
		case Bin_LeftConfig:
			AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
			AddSequential(new WaveWait(0.5));
			AddSequential(new BinJugglerCommand(Bin_LeftLock, Off));
			AddSequential(new BinJugglerCommand(Bin_RightLock, On));
			break;
		case Bin_RightConfig:
			AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
			AddSequential(new WaveWait(0.5));
			AddSequential(new BinJugglerCommand(Bin_LeftLock, On));
			AddSequential(new BinJugglerCommand(Bin_RightLock, Off));
			break;
		default:
			//Do nothing
			break;
	}


}
