#ifndef WaitForSensor_H
#define WaitForSensor_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "WaveConstants.h"

class WaitForSensor: public CommandBase
{
public:
	WaitForSensor(int sensor, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int m_sensor;
	double m_timeout;
};

#endif
