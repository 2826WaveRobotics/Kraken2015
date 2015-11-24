#ifndef SET_RECYCLER_POSITION_H
#define SET_RECYCLER_POSITION_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetRecyclerPosition: public CommandBase
{
public:
	SetRecyclerPosition(bool setUp, double speed, bool getLock);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool m_setUp; //direction
	float m_speed; //speed
	bool m_getLock;
};

#endif
