#ifndef StackATote_H
#define StackATote_H

#include "../CommandBase.h"
#include "WPILib.h"

class StackATote: public CommandBase
{
public:
	StackATote();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
