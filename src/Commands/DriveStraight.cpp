#include "DriveStraight.h"

DriveStraight::DriveStraight()
{
	m_distanceToDrive = 0;
}
DriveStraight::DriveStraight(double distance)
{
	m_distanceToDrive = distance;
}

void DriveStraight::Initialize()
{

}

void DriveStraight::Execute()
{

}

bool DriveStraight::IsFinished()
{
	return true;
}

void DriveStraight::End()
{

}

void DriveStraight::Interrupted()
{
	End();
}
