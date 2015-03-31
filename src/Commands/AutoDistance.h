#ifndef AUTO_DISTANCE_H
#define AUTO_DISTANCE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDistance: public CommandBase
{
public:
	AutoDistance(double maxDistance, double power, double minPower, float direction);
	AutoDistance(double maxDistance, double power, double minPower, float direction,
			bool special, double distanceTolerance, double velocityTolerance, double midpointMultiplier);
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
	double m_velocity;
	double m_minPower;
	bool m_specialCase;

	double m_distanceTolerance;
	double m_velocityTolerance;
	double m_midpointMultiplier;
};

#endif
