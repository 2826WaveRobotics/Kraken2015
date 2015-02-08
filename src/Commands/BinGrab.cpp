#include "BinGrab.h"
#include "../Robot.h"

BinGrab::BinGrab(bool held)
{
	m_handleHolder = held;
}

void BinGrab::Initialize()
{

	Robot::m_recycler->SetHandleHolder(m_handleHolder);

}


void BinGrab::Execute()
{

}

bool BinGrab::IsFinished()
{
	return true;
}

void BinGrab::End()
{

}

void BinGrab::Interrupted()
{
	End();
}
