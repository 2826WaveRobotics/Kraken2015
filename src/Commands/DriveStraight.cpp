#include "DriveStraight.h"
#include "../Robot.h"

DriveStraight::DriveStraight()
{
	m_distanceToDrive = 0;
}
DriveStraight::DriveStraight(double distance)
{
	m_distanceToDrive = distance;
}

void DriveStraight::Initialize()
{
	Robot::m_drive->SetCoefPower(-.25);
}

void DriveStraight::Execute()
{
	double leftCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(2) / 10);
	double rightCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(3) / 10);
	double leftPower = -.25*leftCoef;
	double rightPower = -.25*rightCoef;

	std::cout << "Left Ticks: " << Robot::m_drive->GetLeftEncoder() << "\tRight Ticks: " << Robot::m_drive->GetRightEncoder() << "\tLeft Distance: " <<
			Robot::m_drive->GetLeftDistanceTravelled() << "\tRight Distance: " << Robot::m_drive->GetRightDistanceTravelled() <<
			"\tLeft Coef: " << leftCoef << "\tRight Coef: " << rightCoef << "\tLeft Power: " << leftPower << "\tRight Power: " << rightPower << std::endl;
}

bool DriveStraight::IsFinished()
{
	double averageEncoder = (Robot::m_drive->GetLeftEncoder() + Robot::m_drive->GetRightEncoder()) / 2;
	double distanceTravelled = averageEncoder*circumference*ticksPerWheel;

	if(/*(distanceTravelled >= m_distanceToDrive) ||*/ Robot::m_intake->IsFrontSensorTripped()){
		return true;
	}
	else{
		return false;
	}
}

void DriveStraight::End()
{
	Robot::m_drive->SetCoefPower(0);
}

void DriveStraight::Interrupted()
{
	//End();
}
