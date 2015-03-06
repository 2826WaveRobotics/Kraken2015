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
	Robot::m_drive->SetCoefPower(m_drivePower);
	m_gTG = 1;
	m_swaggerson = 0;
	DS_timer->Start();
	if(Robot::m_intake->IsFrontSensorTripped())
	{
		m_startTripped = 1;
		m_gTG = 0;
	}
}

void DriveStraight::Execute()
{
//	double leftCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(2) / 10);
//	double rightCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(3) / 10);
//	double leftPower = -.25*leftCoef;
//	double rightPower = -.25*rightCoef;
//

	if(m_startTripped && !Robot::m_intake->IsFrontSensorTripped())
	{
		m_startTripped = 0;
		m_swaggerson = 1;
		DS_timer->Reset();
	}
	if((DS_timer->Get() > .05) && (!Robot::m_intake->IsFrontSensorTripped())&& m_swaggerson){
		m_gTG = 1;
	}



//	std::cout << "Left Ticks: " << Robot::m_drive->GetLeftEncoder() << "\tRight Ticks: " << Robot::m_drive->GetRightEncoder() << "\tLeft Distance: " <<
//			Robot::m_drive->GetLeftDistanceTravelled() << "\tRight Distance: " << Robot::m_drive->GetRightDistanceTravelled() <<
//			"\tLeft Coef: " << leftCoef << "\tRight Coef: " << rightCoef << "\tLeft Power: " << leftPower << "\tRight Power: " << rightPower << std::endl;
}

bool DriveStraight::IsFinished()
{
	double averageEncoder = (Robot::m_drive->GetLeftEncoder() + Robot::m_drive->GetRightEncoder()) / 2;
	double distanceTravelled = fabs(averageEncoder*circumference*ticksPerWheel);
	std::cout << "Distance" << distanceTravelled << std::endl;

	if(/*(distanceTravelled >= m_distanceToDrive) ||*/ (Robot::m_intake->IsFrontSensorTripped() && m_gTG)){ //sensor isnt tripped and we are good to go
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
