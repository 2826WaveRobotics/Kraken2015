#include "Auto.h"
#include "WaveConstants.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "DriveStraight.h"
#include "SetElevatorPosition.h"
#include "Intake_FrontTote.h"
#include "ToteWait.h"
#include "LoadMagazine.h"
#include "ResetRecycler.h"
#include "AutoDrive.h"
#include "AutoRecycle.h"

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
	AddSequential(new WaveWait(.00));
	AddParallel(new Intake_FrontTote());//Run intake until a tote is seated in the elevator
	AddParallel(new AutoDrive(64, .35)); // drive 24 inches at 30 percent power
	AddParallel( new AutoRecycle(Bin_LoadLeft));//lift, grab, un-lift, load to the side
	AddSequential(new LoadMagazine()); //elevator down then up
	AddParallel(new Intake_FrontTote());//wait for a tote
	AddSequential(new WaitForChildren(15));//wait till it works

	//second set

	AddParallel(new AutoDrive(64, .33)); // drive 24 inches at 30 percent power
	AddParallel(new AutoRecycle(Bin_LoadCenter));//lift, grab, un-lift, load to the side
	AddSequential(new LoadMagazine());//elevator down then up
	AddParallel(new Intake_FrontTote());//wait for a tote
	AddSequential(new WaitForChildren(15));//wait till it works

	//third set
	AddParallel(new SetElevatorPosition(lowElevatorPosition));
	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
	AddSequential(new WaveWait(.05));
	AddParallel(new SetRecyclerPosition(up)); // bring the bin up to the top
	AddSequential(new SetElevatorPosition(autoElevatorPosition));








/*

//	AddSequential(new WaveWait(.15));
//	AddSequential(new WaveWait(.05));
//	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
//	AddSequential(new WaveWait(.025));
//	AddSequential(new SetRecyclerPosition(down)); //  bring the recycler back down for the second bin
	AddSequential(new ResetRecycler());
//	AddParallel(new BinJugglerCommand(Bin_LoadLeft));
//	AddSequential(new WaveWait(.05));
//	AddParallel(new BinJugglerCommand(Bin_LoadLeft));
//	AddSequential(new Intake_FrontTote()); // wait until tote is in the robot
	AddSequential(new WaitForChildren(4));
//  // second set
//
	AddSequential(new BinJugglerCommand(Bin_LoadLeft));
	AddSequential(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin at the top
	AddParallel(new LoadMagazine());
	AddSequential(new SetPneumatics(cyl_hooks, release)); // open the appropriate hook
	AddSequential(new SetRecyclerPosition(up)); // lift the bin up
	AddSequential(new SetPneumatics(cyl_hooks, grab)); // open the appropriate hook
	AddSequential(new WaitForChildren(4));
	//AddSequential(new SetElevatorPosition(highElevatorPosition));
	//AddSequential(new WaveWait(.05));
	//AddSequential(new ToteWait(15));
	AddParallel(new AutoDrive(24, .3)); // drive 24 inches at 30 percent power
	AddParallel(new Intake_FrontTote());
//	AddSequential(new WaveWait(.15));
//	AddSequential(new WaveWait(.05));
//	AddSequential(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
//	AddSequential(new WaveWait(.025));
//	AddSequential(new SetRecyclerPosition(down)); //  bring the recycler back down for the second bin
	AddSequential(new ResetRecycler());
//	AddSequential(new WaveWait(.05));
//	AddParallel(new BinJugglerCommand(Bin_LoadLeft));
//	AddSequential(new Intake_FrontTote()); // wait until tote is in the robot
	AddSequential(new WaitForChildren(4));



//	AddParallel(new SetElevatorPosition(lowElevatorPosition));
//	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin in front of us
//	AddParallel(new SetPneumatics(cyl_leftHook, release)); // open the appropriate hook
//	AddSequential(new WaveWait(.05));
//	//AddSequential(new WaveWait(.05));
//	AddSequential(new SetRecyclerPosition(up)); // bring the tote up to the bin juggler
//	AddParallel(new SetPneumatics(cyl_leftHook, grab)); // grab on to the bin
//	AddSequential(new WaveWait(.05));
//	AddParallel(new SetElevatorPosition(highElevatorPosition));
//	AddSequential(new WaveWait(.3));
//	AddParallel(new AutoDrive(24, .27)); // drive 24 inches at 27 percent power
//	AddParallel(new SetPneumatics(cyl_handleHolder, open)); // release the bin from the track
//	AddSequential(new WaveWait(.05));
//	 // drive 24 inches at 25 percent power
//	AddParallel(new SetRecyclerPosition(down)); // bring the recycler back down for the 3rd bin
//	AddSequential(new WaveWait(.1));
//	AddParallel(new BinJugglerCommand(Bin_LoadCenter));
//	AddSequential(new ToteWait(15));
//	AddSequential(new Intake_FrontTote()); // wait until tote is in the robot
//
//
//	//third bin
//	AddParallel(new SetElevatorPosition(lowElevatorPosition));
//	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
//	AddSequential(new WaveWait(.05));
//	AddParallel(new SetRecyclerPosition(up)); // bring the bin up to the top
//	AddSequential(new SetElevatorPosition(lowElevatorPosition));
//	AddSequential(new SetElevatorPosition(autoElevatorPosition));
 *
 */
}

