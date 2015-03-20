#ifndef DRIVE_STRAIGHT_H
#define DRIVE_STRAIGHT_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
public:
	DriveStraight();
	DriveStraight(double distance, double power = -.25);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

	bool m_distanceToDrive;
	double m_drivePower;
};

#endif
