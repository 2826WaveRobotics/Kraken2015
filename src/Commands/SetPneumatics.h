#ifndef SetPneumatics_H
#define SetPneumatics_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetPneumatics: public CommandBase
{
public:
	SetPneumatics(int cylinder, bool open);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int m_cylinder;
	bool m_open;
};

#endif
