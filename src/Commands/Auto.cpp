#include "Auto.h"
#include "WaveConstants.h"
#include "DrivePoweredDistance.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "SetElevatorPosition.h"
#include "DriveStraight.h"
#include "Intake_FrontTote.h"
#include "ToteWait.h"

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
	//AddSequential(new WaveWait(.05));
	AddSequential(new ToteWait(15));
	AddParallel(new DriveStraight(24, -.3)); // drive 24 inches at 25 percent power
	AddSequential(new SetRecyclerPosition(up)); // lift the bin up
	AddSequential(new WaveWait(.15));
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // grab on to the bin at the top
	AddSequential(new WaveWait(.05));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.025));
	AddParallel(new SetRecyclerPosition(down)); //  bring the recycler back down for the second bin
	AddSequential(new WaveWait(.05));
	AddParallel(new BinJugglerCommand(Bin_LoadLeft));
	AddSequential(new Intake_FrontTote()); // wait until tote is in the robot

  // second set

	AddParallel(new SetElevatorPosition(lowElevatorPosition));
	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin in front of us
	AddParallel(new SetPneumatics(cyl_leftHook, release)); // open the appropriate hook
	AddSequential(new WaveWait(.05));
	//AddSequential(new WaveWait(.05));
	AddParallel(new DriveStraight(24, -.27)); // drive 24 inches at 25 percent power
	AddSequential(new SetRecyclerPosition(up)); // bring the tote up to the bin juggler
	AddParallel(new SetElevatorPosition(highElevatorPosition));
	AddSequential(new WaveWait(.1));
	AddParallel(new SetPneumatics(cyl_leftHook, grab)); // grab on to the bin
	AddSequential(new WaveWait(.05));
	AddParallel(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.05));
	 // drive 24 inches at 25 percent power
	AddParallel(new SetRecyclerPosition(down)); // bring the recycler back down for the 3rd bin
	AddSequential(new WaveWait(.1));
	AddParallel(new BinJugglerCommand(Bin_LoadCenter));
	AddSequential(new ToteWait(15));
	AddSequential(new Intake_FrontTote()); // wait until tote is in the robot


	//third bin
	AddParallel(new SetElevatorPosition(lowElevatorPosition));
	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
	AddSequential(new WaveWait(.05));
	AddParallel(new SetRecyclerPosition(up)); // bring the bin up to the top
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(autoElevatorPosition));
}

