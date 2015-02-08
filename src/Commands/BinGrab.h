#ifndef BIN_GRAB_H
#define BIN_GRAB_H

#include "../CommandBase.h"
#include "WPILib.h"

class BinGrab: public CommandBase
{
public:
	BinGrab(bool held);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

	bool m_handleHolder;

};

#endif
