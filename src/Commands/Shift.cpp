#include "Shift.h"
#include "../Robot.h"
#include "../WaveConstants.h"

Shift::Shift(bool highGear)
{
	drive = Robot::m_drive;
	m_highGear = highGear;
}

void Shift::Initialize()
{
	if(m_highGear == true)
	{
		drive->ShiftGear(true);
	}
	else
	{
		drive->ShiftGear(false);
	}
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

}

void Shift::Interrupted()
{
	End();
}
