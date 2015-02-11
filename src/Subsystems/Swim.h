#ifndef Swim_H
#define Swim_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class Swim: public PIDSubsystem
{
public:
	Swim();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Start();


private:
	Encoder* m_leftSwimEncoder;
	Encoder* m_rightSwimEncoder;
	CANTalon* m_leftSwim1;
	CANTalon* m_leftSwim2;
	CANTalon* m_rightSwim1;
	CANTalon* m_rightSwim2;
	RobotDrive* m_robotSwim;
};

#endif
