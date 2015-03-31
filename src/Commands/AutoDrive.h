#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDrive: public CommandBase
{
public:
	AutoDrive(double maxDistance, double power, float direction);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_distance;
	double m_power;
	float m_direction;
	double m_distanceTraveled;
	double m_maxPower;
};

#endif
