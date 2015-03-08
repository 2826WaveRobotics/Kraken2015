#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

//#define NULL = 0;

const double Elevator_UpperVolts = 4.267;
const double Elevator_LowerVolts = .795;
const double Elevator_UpperInches = 31.822;
const double Elevator_LowerInches = 8.67;
const double Elevator_UpperStop = Elevator_UpperInches - 1.5;
const double Elevator_LowerStop = Elevator_LowerInches + .5;
const double highElevatorPosition= 29; // Jake wants this 3/1 1AM
const double lowElevatorPosition= 9.03;
const double autoElevatorPosition= 13.81;
const double stackClearanceElevatorPosition= 25;
const double elevatorTolerance = 0.25;
const double bumpHeight = 3.0;
const int On=1;
const int Off=0;
const double binCylinderWait = 0.5;
const double pi = 3.1415926354;
const double circumference = ((3/16)+6)*pi;
const double ticksPerWheel = 1/(256*3*2.5); // 256 ticks per encoder * (3:1) * (5:2)

const double toteLoad0 = .625; //.4375;
const double toteLoad1 = .75; //.625;
const double toteLoad2 = 1.0625; //.9375;
const double toteLoad3 = 1.375; //1.5;
const double toteLoad3B = 2.4375; //2.125;
const double toteLoad4 = 1.9375; //2.125;
const double toteLoad4B = 3.3125; //3.25;
const double toteLoad5 = 2.6875; //2.875;
const double toteLoad5B = 4.25; //4.375;
const double toteLoad6 = 3.4375; //0;
const double toteLoad6B = 4.875; //0;


//An enumeration is a numbered list of variables
enum
{
	Bin_LoadCenter = 0,
	Bin_LoadLeft, //This has a value of 1
	Bin_LoadRight, //This has a value of 2
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

#endif
