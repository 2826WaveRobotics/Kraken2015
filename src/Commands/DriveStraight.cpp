#include "DriveStraight.h"
#include "../Robot.h"

DriveStraight::DriveStraight()
{
	m_distanceToDrive = 0;
}
DriveStraight::DriveStraight(double distance, double power)
{
	m_distanceToDrive = distance;
	m_drivePower = power;
}

void DriveStraight::Initialize()
{
	std::cout << "DriveStraight: Initialize" << std::endl;
	Robot::m_drive->SetPower(.3);
	Robot::m_drive->MoveStraight(0);
}

void DriveStraight::Execute()
{
	std::cout << "DriveStraight: Execute" << std::endl;
	double correction = Robot::m_drive->GetPIDOutput();
	std::cout << "Correction Power: " << correction << std::endl;
	Robot::m_drive->SetSidePower(m_drivePower + correction, m_drivePower - correction);
	std::cout << "Setting Power (L:R) ~ " << (m_drivePower + correction) << "\t" <<
			(m_drivePower - correction) << std::endl;
}

bool DriveStraight::IsFinished()
{
	return false;
}

void DriveStraight::End()
{

}

void DriveStraight::Interrupted()
{
	//End();
}
