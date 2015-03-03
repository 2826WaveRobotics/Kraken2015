#include "Auto.h"
#include "WaveConstants.h"
#include "DrivePoweredDistance.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "SetElevatorPosition.h"
#include "DriveStraight.h"
#include "Intake_FrontTote.h"

namespace{
bool up = true;
bool down = false;
bool grab = false;
bool release = true;
bool open = true;
bool close = false;
}

Auto::Auto()
{
	//first set
	AddSequential(new Intake_FrontTote());
	AddParallel(new SetPneumatics(cyl_hooks, release)); // open the appropriate hook
	AddParallel(new SetElevatorPosition(highElevatorPosition));
	AddSequential(new SetRecyclerPosition(up)); // lift the bin up
	AddSequential(new WaveWait(.05));
	AddParallel(new DriveStraight(24)); // drive 24 inches at 25 percent power
	AddSequential(new WaveWait(.1));
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // grab on to the bin at the top
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.025));
	AddParallel(new SetRecyclerPosition(down)); //  bring the recycler back down for the second bin
	AddParallel(new BinJugglerCommand(Bin_LoadLeft));
	AddSequential(new Intake_FrontTote());

  // second set
	AddParallel(new SetElevatorPosition(lowElevatorPosition));
	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin in front of us
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(cyl_hooks, release)); // open the appropriate hook
	AddSequential(new WaveWait(.05));
	AddSequential(new SetRecyclerPosition(up)); // bring the tote up to the bin juggler
	AddSequential(new WaveWait(.15));
	AddParallel(new SetElevatorPosition(AutoElevatorPosition));
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // grab on to the bin
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.05));
	 // drive 24 inches at 25 percent power
	AddSequential(new SetRecyclerPosition(down)); // bring the recycler back down for the 3rd bin
	AddSequential(new WaveWait(.1));
	AddParallel(new SetElevatorPosition(highElevatorPosition));
	AddParallel(new BinJugglerCommand(Bin_LoadCenter));
	AddSequential(new WaveWait(.05));
	AddSequential(new DriveStraight(24));

	//third bin
	AddParallel(new SetElevatorPosition(lowElevatorPosition));
	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
	AddSequential(new WaveWait(.05));
	AddParallel(new SetRecyclerPosition(up)); // bring the bin up to the top
	AddSequential(new WaveWait(.2));
	AddSequential(new SetElevatorPosition(AutoElevatorPosition));
}

