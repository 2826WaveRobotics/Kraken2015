#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

//#define NULL = 0;
#define COMPETITION_BOT

#ifdef COMPETITION_BOT
const double Elevator_UpperVolts = .72998; // remember to change this value between sensors
const double Elevator_LowerVolts = 4.28933;
const double Elevator_UpperInches = 31.375;
const double Elevator_LowerInches = 8;

const double highElevatorPosition= 29; // Jake wants this 3/1 1AM
const double lowElevatorPosition= 8; //9.03
const double ScoreElevatorPosition= 13.81;
const double stackClearanceElevatorPosition= 25.25;
const double elevatorEngagedPosition= 10.75;

#endif

#ifdef PRACTICE_BOT
const double Elevator_UpperVolts = .72998; // remember to change this value between sensors
const double Elevator_LowerVolts = 4.28933;
const double Elevator_UpperInches = 33;
const double Elevator_LowerInches = 10.5;

const double highElevatorPosition= 33; // Jake wants this 3/1 1AM
const double lowElevatorPosition= 10.5;
const double ScoreElevatorPosition= 16;
const double stackClearanceElevatorPosition= 28;
const double elevatorEngagedPosition= 13;

#endif


const double Elevator_UpperStop = Elevator_UpperInches - 0.0; //1.0;
const double Elevator_LowerStop = Elevator_LowerInches + 0.0;

const double elevatorTolerance = 0.25;
const double bumpHeight = 3.0;
const int On=1;
const int Off=0;
const double binCylinderWait = 0.75;
const double pi = 3.1415926354;
const double circumference = ((3/16)+6)*pi;
const double ticksPerWheel = 1/(256*3*2.5); // 256 ticks per encoder * (3:1) * (5:2)


//An enumeration is a numbered list of variables
enum
{
	Bin_LoadCenter = 0,
	Bin_LoadLeft, //This has a value of 1
	Bin_LoadRight, //This has a value of 2
};

enum // debug modes
{
	debug_driveCoefficients,
	debug_PIDs,
	debug_DIOs,
	debug_elevator,
	debug_driveClock

};

enum
{
	Bin_LiftCylinder = 0,
	Bin_LeftLock, //This has a value of 1
	Bin_RightLock, //This has a value of 2
	Bin_LeftHook,
	Bin_RightHook
};

enum
{
	Bin_SameToSame = 0,
	Bin_CenterToLeft,
	Bin_CenterToRight,
	Bin_CenterToTight,
	Bin_LeftToCenter,
	Bin_LeftToRight,
	Bin_LeftToTight,
	Bin_RightToCenter,
	Bin_RightToLeft,
	Bin_RightToTight,
	Bin_TightToCenter,
	Bin_TightToLeft,
	Bin_TightToRight
};

enum
{
	BinJugglerSequence = 0
};

enum
{
	Bin_CenterActive = 0,
	Bin_LeftActive, //This has a value of 1
	Bin_RightActive, //This has a value of 2
	Bin_TightActive
};

enum
{
	Tote_Carry0 = 0,
	Tote_Carry1, //This has a value of 1
	Tote_Carry2, //This has a value of 2
	Tote_Carry3,
	Tote_Carry4,
	Tote_Carry5,
	Tote_Carry6
};

enum
{
	Axis_LX = 0,
	Axis_LY,        //1
	Axis_LTrigger,  //2
	Axis_RTrigger,  //3
	Axis_RX,        //4
	Axis_RY         //5
};
enum
{//A,B,X,Y,L,R,B,S,L,R
	Button_Nothing = 0,
	Btn_A,
	Btn_B,
	Btn_X,
	Btn_Y,
	Btn_LBump,
	Btn_RBump,
	Btn_Back,
	Btn_Start,
	Btn_LJoy,
	Btn_RJoy
};


enum
{
	cyl_leftHook = 0,
	cyl_rightHook,
	cyl_handleHolder,
	cyl_liftCylinder,
	cyl_leftLock,
	cyl_rightLock,
	cyl_shifter,
	cyl_toteHolder,
	cyl_hooks // for commands that need to determine which hook to use
};

enum
{
	dio_tote = 0,
	dio_bin,
	dio_recyclerLower,
	dio_recyclerUpper
};

enum{
	mode_straight = 0,
	mode_distance,
	mode_velocity
};

#endif
