/* Begin Old Auto Mode Stuff

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
 */ //End Old Auto Mode Stuff
