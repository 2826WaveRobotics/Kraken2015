#ifndef EMPTY_CHAMBER_H
#define EMPTY_CHAMBER_H

#include "../CommandBase.h"
#include "WPILib.h"

class EmptyChamber: public CommandBase
{
public:
	EmptyChamber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//float m_inches;
	//double m_motorValue;
};

#endif
