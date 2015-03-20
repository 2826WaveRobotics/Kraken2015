#ifndef AutoCurve_H
#define AutoCurve_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoCurve: public CommandBase
{
public:
	AutoCurve(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_angle;
};

#endif
