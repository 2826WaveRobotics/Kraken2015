#ifndef AUTO_DRIVE_H
#define AUTO_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDrive: public CommandBase
{
public:
	AutoDrive(double distance = 999, double power = .25);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_distanceToDrive;
	double m_power;
	bool m_intakeCleared;
	bool m_ImWaitingForATote;
	bool m_checkingTime;
	bool m_WeFoundTote;
	double m_distanceTravelled;
	bool m_farEnough;
	Timer m_timer;
};

#endif
