#ifndef SETCANGRABBER_H
#define SETCANGRABBER_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetCanGrabber: public CommandBase
{
public:
	SetCanGrabber(bool setOpen);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_setOpen;
};


#endif
