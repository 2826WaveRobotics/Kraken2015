#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

//#define NULL = 0;

const double highElevatorPosition=13.0;
const double lowElevatorPosition=1.0;
const int On=1;
const int Off=0;
const double binCylinderWait = 0.5;


//An enumeration is a numbered list of variables
enum
{
	Bin_CenterConfig = 0,
	Bin_LeftConfig, //This has a value of 1
	Bin_RightConfig //This has a value of 2
};

enum
{
	Bin_LiftCylinder = 0,
	Bin_LeftLock, //This has a value of 1
	Bin_RightLock //This has a value of 2
};

enum
{
	Bin_SameToSame = 0,
	Bin_CenterToLeft,
	Bin_CenterToRight,
	Bin_LeftToCenter,
	Bin_LeftToRight,
	Bin_RightToCenter,
	Bin_RightToLeft
};

enum
{
	Bin_CenterActive = 0,
	Bin_LeftActive, //This has a value of 1
	Bin_RightActive //This has a value of 2
};

#endif
