#ifndef SetTotes_H
#define SetTotes_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetTotes: public CommandBase
{
public:
	SetTotes(bool relative, float totes);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_relative;
	float m_totes;
};

#endif
