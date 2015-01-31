#ifndef WAVECONSTANTS_H
#define WAVECONSTANTS_H

//#define NULL = 0;

const double highElevatorPosition=13.0;
const double lowElevatorPosition=1.0;
const int On=1;
const int Off=0;


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

#endif
