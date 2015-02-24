#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

//#define NULL = 0;

const double highElevatorPosition=4.2;
const double lowElevatorPosition=0.89;
const double elevatorTolerance = 0.3;
const double bumpHeight = 3.0;
const int On=1;
const int Off=0;
const double binCylinderWait = 0.5;


//An enumeration is a numbered list of variables
enum
{
	Bin_CenterConfig = 0,
	Bin_LeftConfig, //This has a value of 1
	Bin_RightConfig, //This has a value of 2
	Bin_TightConfig // This has a value of 3
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


#endif
