#include "AutoMode_ShootTotes.h"
#include "WaveConstants.h"
#include "SetPneumatics.h"
#include "BinJugglerCommand.h"
#include "SetRecyclerPosition.h"
#include "DriveStraight.h"
#include "SetElevatorPosition.h"
#include "Intake_FrontTote.h"
#include "LoadMagazine.h"
#include "ResetRecycler.h"
#include "AutoDrive.h"
#include "AutoCurve.h"
#include "AutoRecycle.h"
#include "SetFrontIntake.h"
#include "KillDriveStraight.h"
#include "AutoDistance.h"
#include "WaitForBin.h"

namespace{
bool up = true;
//bool down = false;
//bool grab = false;
//bool release = true;
//bool open = true;
bool close = false;
}

AutoMode_ShootTotes::AutoMode_ShootTotes()
{
	//first set
	AddSequential(new WaveWait(0.00));
	//AddSequential(new SetPneumatics(cyl_handleHolder, close));
	//AddSequential(new WaveWait(.1));
	AddParallel(new AutoDrive(1000,.35, 0)); // drive 24 inches at 30 percent power // .3
	AddParallel(new AutoRecycle(Bin_LoadRight,cyl_leftHook));//lift, grab, un-lift, load to the side
	AddSequential(new Intake_FrontTote(.45));//Run intake until a tote is seated in the elevator // .4 // .33
	AddSequential(new SetElevatorPosition(stackClearanceElevatorPosition)); //elevator up
	AddSequential(new Intake_FrontTote(.45));//wait for a tote / .4

	//second set
	//AddSequential(new WaitForBin()); // move some distance forwards instead of time // 3in
	AddSequential(new AutoDrive(3, .27, 0)); //- uncomment to switch to distance for sensing bin

	AddParallel(new AutoRecycle(Bin_LoadCenter, cyl_rightHook));//lift, grab, un-lift, load to the side
	AddParallel(new AutoDrive(92, .35, 1.5)); // -1.5 is a new setpoint for the gyro [COMPETITION ROBOT]
	AddSequential(new LoadMagazine(stackClearanceElevatorPosition));//elevator down then up
	AddSequential(new Intake_FrontTote(.45));//wait for 3rd tote // .4
	//AddSequential(new KillDriveStraight());

	//third set
	AddParallel(new SetElevatorPosition(lowElevatorPosition));

	//AddSequential(new WaitForBin()); // move some distance forwards instead of time //5in //3in
	AddSequential(new AutoDrive(4, .27, 0/* 1.5*/));// - uncomment to switch to distance for sensing bin

	AddParallel(new SetPneumatics(cyl_handleHolder, close)); // grab on to the bin with the track
	AddParallel(new WaveWait(0));
	AddSequential(new KillDriveStraight());
	//AddParallel(new AutoDrive(-24, -.1));//Stop moving forward {Connor Added}
	AddParallel(new SetRecyclerPosition(up,.8)); // bring the bin up to the top [.8 speed up on the last bin

	AddParallel(new LoadMagazine(elevatorEngagedPosition)); // [for swapping wheels] AddParallel(new LoadMagazine(autoElevatorPosition));

	AddSequential(new WaveWait(0.6));
	//Turn
	AddSequential(new AutoCurve(65)); //Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~ Curve ~
	AddParallel(new LoadMagazine(lowElevatorPosition));

	//AddSequential(new AutoDistance(81, .75, 90));
	//AddSequential(new AutoDistance(44, .18, 90)); // 58 //52
	AddSequential(new AutoDistance(110, 1.6, .22, 65, true, 1, 4, .8)); //max speed doesn't necessarily mean max speed
	//for above - true means special values, 1 is distance tolerace, 4 is velocity tolerance, .8 is midpoint multiplier

	AddParallel(new SetFrontIntake(1,5));

	//AddSequential(new AutoDistance(-11, -.35, 90)); //AddSequential(new AutoDrive(-12, -.35, 90));
	//AddSequential(new AutoDistance(-7, .18, 90)); // -10in //-20 //-12
	AddSequential(new AutoDrive(-24, -.35, 30));
	//AddSequential(new AutoDistance(-18, -.25, -.18, 0));

	AddParallel(new SetFrontIntake(0,3));

	AddSequential(new AutoCurve(90));

	AddSequential(new AutoDistance(40, .55, .18, 90));
	//5.1726314789

	//massive block of old auto moved to new file, "TooValuableToDeleteButNotNeeded.h"
}

