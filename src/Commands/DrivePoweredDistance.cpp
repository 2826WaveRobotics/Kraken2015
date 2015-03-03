#include "DrivePoweredDistance.h"
#include "Robot.h"
#include "WaveConstants.h"

DrivePoweredDistance::DrivePoweredDistance(double inches, double power)
{
	m_inches = inches;
	m_power = power;
}

// Called just before this Command runs the first time
void DrivePoweredDistance::Initialize()
{
	Robot::m_drive->ResetEncoders();
	Robot::m_drive->SetPower(m_power);
}

// Called repeatedly when this Command is scheduled to run
void DrivePoweredDistance::Execute()
{
	double leftCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(2) / 10);
	double rightCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(3) / 10);
	double leftPower = m_power*leftCoef;
	double rightPower = m_power*rightCoef;

	std::cout << "Left Ticks: " << Robot::m_drive->GetLeftEncoder() << "\tRight Ticks: " << Robot::m_drive->GetRightEncoder() << "\tLeft Distance: " <<
			Robot::m_drive->GetLeftDistanceTravelled() << "\tRight Distance: " << Robot::m_drive->GetRightDistanceTravelled() <<
			"\tLeft Coef: " << leftCoef << "\tRight Coef: " << rightCoef << "\tLeft Power: " << leftPower << "\tRight Power: " << rightPower << std::endl;

}

// Make this return true when this Command no longer needs to run execute()
bool DrivePoweredDistance::IsFinished()
{
	double averageEncoder = (Robot::m_drive->GetLeftEncoder() + Robot::m_drive->GetRightEncoder()) / 2;
	double distanceTravelled = averageEncoder*circumference*ticksPerWheel;

	if(distanceTravelled >= m_inches){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void DrivePoweredDistance::End()
{
	Robot::m_drive->SetPower(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivePoweredDistance::Interrupted()
{

}
