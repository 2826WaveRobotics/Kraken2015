#include "Shift.h"
#include "../Robot.h"
#include "../WaveConstants.h"

Shift::Shift(bool highGear)
{
//	drive = Robot::m_drive;
	m_highGear = highGear;
}

void Shift::Initialize()
{
	drive = Robot::m_drive;
	std::cout << "Shift Initialized, is Drive NULL?" << (NULL == drive ? "NULL":"Good") << std::endl;
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
	std::cout << "Shift Executing" << std::endl;
}

bool Shift::IsFinished()
{
	std::cout << "Is Shift Finished?" << std::endl;
	return true;
}

void Shift::End()
{
	std::cout << "Shift ended" << std::endl;
}

void Shift::Interrupted()
{
	std::cout << "Shift Interrupted" << std::endl;
	End();
}
