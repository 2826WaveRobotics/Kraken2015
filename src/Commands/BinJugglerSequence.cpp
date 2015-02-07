#include "BinJugglerSequence.h"
#include "BinJugglerCommand.h"

BinJugglerSequence::BinJugglerSequence(int configuration) {
	//Build command sequence here
	//AddSequential(new CommandName());


	//	AddSequential(new BinJugglerCommand(0, 0));


	if((currentPosition == Bin_CenterActive) && (configuration == Bin_LeftConfig))
	{
		set = Bin_CenterToLeft;
	}
	else if((currentPosition == Bin_CenterActive) && (configuration == Bin_RightConfig))
	{
		set = Bin_CenterToRight;
	}
	else if((currentPosition == Bin_LeftActive) && (configuration == Bin_CenterConfig))
	{
		set = Bin_LeftToCenter;
	}
	else if((currentPosition == Bin_LeftActive) && (configuration == Bin_RightConfig))
	{
		set = Bin_LeftToRight;
	}
	else if((currentPosition == Bin_RightActive) && (configuration == Bin_CenterConfig))
	{
		set = Bin_RightToCenter;
	}
	else if((currentPosition == Bin_RightActive) && (configuration == Bin_LeftConfig))
	{
		set = Bin_RightToLeft;
	}
	else
	{
		set = Bin_SameToSame;
	}


	switch(set)
	{
	case Bin_CenterToLeft:
		AddSequential(new BinJugglerCommand(Bin_RightLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
		AddSequential(new WaveWait(binCylinderWait));
		currentPosition = Bin_LeftActive;
		break;
	case Bin_CenterToRight:
		AddSequential(new BinJugglerCommand(Bin_LeftLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
		AddSequential(new WaveWait(binCylinderWait));
		currentPosition = Bin_RightActive;
		break;
	case Bin_LeftToCenter:
		AddSequential(new BinJugglerCommand(Bin_RightLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, On));
		AddSequential(new WaveWait(binCylinderWait));
		AddSequential(new BinJugglerCommand(Bin_RightLock, On));
		currentPosition = Bin_CenterActive;
		break;
	case Bin_LeftToRight:
		AddSequential(new BinJugglerCommand(Bin_RightLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, On));
		AddSequential(new WaveWait(binCylinderWait));
		AddSequential(new BinJugglerCommand(Bin_RightLock, On));
		AddSequential(new BinJugglerCommand(Bin_LeftLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
		AddSequential(new WaveWait(binCylinderWait));
		currentPosition = Bin_RightActive;
		break;
	case Bin_RightToCenter:
		AddSequential(new BinJugglerCommand(Bin_LeftLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, On));
		AddSequential(new WaveWait(binCylinderWait));
		AddSequential(new BinJugglerCommand(Bin_LeftLock, On));
		currentPosition = Bin_CenterActive;
		break;
	case Bin_RightToLeft:
		AddSequential(new BinJugglerCommand(Bin_LeftLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, On));
		AddSequential(new WaveWait(binCylinderWait));
		AddSequential(new BinJugglerCommand(Bin_LeftLock, On));
		AddSequential(new BinJugglerCommand(Bin_RightLock, Off));
		AddSequential(new BinJugglerCommand(Bin_LiftCylinder, Off));
		AddSequential(new WaveWait(binCylinderWait));
		currentPosition = Bin_LeftActive;
		break;
	case Bin_SameToSame:
		//already there!
		break;
	default:
		//Do nothing
		break;
	}

	Robot::m_binJuggler->setActive(currentPosition);

}
