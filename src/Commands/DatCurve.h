#ifndef DatCurve_H
#define DatCurve_H

#include "../CommandBase.h"
#include "WPILib.h"

class DatCurve: public CommandBase
{
public:
	DatCurve(double power = .25, double degrees = 90);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_power;
	double m_degrees;
	double m_leftPower;
	double m_rightPower;
};

#endif
