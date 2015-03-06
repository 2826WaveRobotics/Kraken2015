#include "AutoTest.h"
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

AutoTest::AutoTest()
{
	//first set
	AddSequential(new Intake_FrontTote());
	AddSequential(new WaveWait(.5));
	AddSequential(new SetPneumatics(cyl_hooks, release)); // open the appropriate hook
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(up)); // lift the bin up
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // grab on to the bin at the top
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(down)); //  bring the recycler back down for the second bin
	AddSequential(new WaveWait(.25));
	AddSequential(new SetElevatorPosition(highElevatorPosition));
	AddSequential(new WaveWait(.25));
	AddParallel(new Intake_FrontTote());
	AddSequential(new WaveWait(.5));
	AddSequential(new DriveStraight(24)); // drive 24 inches at 25 percent power
	AddSequential(new WaveWait(.25));

  // second set
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new SetElevatorPosition(autoElevatorPosition));
	AddSequential(new WaveWait(.5));
	AddSequential(new BinJugglerCommand(Bin_LoadLeft)); // Switch the arms so a new one is ready
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin in front of us
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_hooks, release)); // open the appropriate hook
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(up)); // bring the tote up to the bin juggler
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // grab on to the bin
	AddSequential(new WaveWait(.25));
	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(down)); // bring the recycler back down for the 3rd bin
	AddSequential(new WaveWait(.25));
	AddSequential(new BinJugglerCommand(Bin_LoadCenter));
	AddSequential(new WaveWait(.25));
	AddSequential(new SetElevatorPosition(highElevatorPosition));
	AddSequential(new WaveWait(.25));
	AddParallel(new Intake_FrontTote());
	AddSequential(new WaveWait(.5));
	AddSequential(new DriveStraight(24)); // drive 24 inches at 25 percent power
	AddSequential(new WaveWait(.25));

	//third bin
	AddSequential(new SetElevatorPosition(lowElevatorPosition));
	AddSequential(new WaveWait(.5));
	AddSequential(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
	AddSequential(new WaveWait(.25));
	AddSequential(new SetRecyclerPosition(up)); // bring the bin up to the top
	AddSequential(new WaveWait(.25));
	AddSequential(new SetElevatorPosition(autoElevatorPosition));

}

