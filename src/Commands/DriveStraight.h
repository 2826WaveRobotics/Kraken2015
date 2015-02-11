#ifndef DRIVE_STRAIGHT_H
#define DRIVE_STRAIGHT_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraight: public CommandBase
{
public:
	DriveStraight();
	DriveStraight(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:

	bool m_distanceToDrive;

};

#endif
