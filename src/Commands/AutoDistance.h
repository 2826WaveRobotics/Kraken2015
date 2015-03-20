#ifndef AutoDistance_H
#define AutoDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDistance: public CommandBase
{
public:
	AutoDistance(double distanceToDrive, double maxPower);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_distanceTraveled;
	double m_distanceToDrive;
	double m_maxPower;
};

#endif
