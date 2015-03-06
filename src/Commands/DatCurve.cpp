#include "DatCurve.h"
#include "Robot.h"

DatCurve::DatCurve(double power, double degrees)
{
	m_power = power;
	m_degrees = degrees;
	m_leftPower = .75;
	m_rightPower = -.1;
}

// Called just before this Command runs the first time
void DatCurve::Initialize()
{
	std::cout << "DatCurve: Initialize" << std::endl;
	SetTimeout(5.0);
	Robot::m_drive->ResetEncoders();
	Robot::m_drive->SetSidePower(m_leftPower, m_rightPower);
}

// Called repeatedly when this Command is scheduled to run
void DatCurve::Execute()
{
	std::cout << "DatCurve: Execute" << std::endl;
	Robot::m_drive->SetSidePower(m_leftPower, m_rightPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DatCurve::IsFinished()
{
	std::cout << "DatCurve: IsFinished?" << std::endl;
	double degreesTurned = 0;
	double leftTurned = Robot::m_drive->GetLeftEncoder();
	double rightTurned = Robot::m_drive->GetRightEncoder();

	if(leftTurned > 100){
		std::cout << "Left Turn is Greater Than 4000" << std::endl;
		Robot::m_drive->SetSidePower(0,0);
		return true;
	}
	else if(IsTimedOut()){
		std::cout << "DatTurn timed out" << std::endl;
		return true;
	}
	else{
		std::cout << "DatCurve is not finished" << std::endl;
		return false;
	}
}

// Called once after isFinished returns true
void DatCurve::End()
{
	std::cout << "DatCurve: End" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DatCurve::Interrupted()
{
	std::cout << "DatCurve: Interrupted" << std::endl;
	//End();
}
