#ifndef SETDRIVEDISTANCE_H
#define SETDRIVEDISTANCE_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetDriveDistance: public CommandBase
{
public:
	SetDriveDistance(double inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	double m_InchesToDrive;
};


#endif
