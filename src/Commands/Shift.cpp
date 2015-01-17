#include "Shift.h"
#include "../Robot.h"
#include "../WaveConstants.h"

Shift::Shift()
{
	shifter = RobotMap::shifter;
}

void Shift::Initialize()
{
	shifter->Set(On);
}

void Shift::Execute()
{

}

bool Shift::IsFinished()
{
	return false;
}

void Shift::End()
{
	shifter->Set(Off);
}

void Shift::Interrupted()
{
	End();
}
