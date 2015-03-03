#ifndef DrivePoweredDistance_H
#define DrivePoweredDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DrivePoweredDistance: public CommandBase
{
public:
	DrivePoweredDistance(double inches, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_inches;
	double m_power;
};

#endif
