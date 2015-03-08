#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDrive: public CommandBase
{
public:
	AutoDrive(double distance = 999, double power = .25, double bearing = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void CalculateTurn();
private:
	double m_minDistanceToDrive;
	double m_maxDistanceToDrive;
	double m_power;
	double m_bearing;

	double m_leftPower;
	double m_rightPower;

	bool m_intakeCleared;
	bool m_ImWaitingForATote;
	bool m_checkingTime;
	bool m_WeFoundTote;
	double m_distanceTravelled;
	bool m_farEnough;
	Timer m_timer;
};

#endif
