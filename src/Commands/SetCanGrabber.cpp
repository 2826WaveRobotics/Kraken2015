#include "SetCanGrabber.h"
#include "../Robot.h"

SetCanGrabber::SetCanGrabber(bool setOpen)
{
	m_setOpen = setOpen;

}

void SetCanGrabber::Initialize()
{
	Robot::m_recycler->canControl(m_setOpen);
}


void SetCanGrabber::Execute()
{

}

bool SetCanGrabber::IsFinished()
{
	return true;
}

void SetCanGrabber::End()
{
}

void SetCanGrabber::Interrupted()
{
	End();
}
