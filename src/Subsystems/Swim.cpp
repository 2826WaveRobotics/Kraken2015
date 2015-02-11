#include "Swim.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

Swim::Swim() :
PIDSubsystem("Swim", 1.0, 0.0, 0.0)
{
	m_leftSwimEncoder = RobotMap::m_driveEncoderLeft;
	m_rightSwimEncoder = RobotMap::m_driveEncoderRight;
	m_leftSwim1 = RobotMap::leftDrive1;
	m_leftSwim2 = RobotMap::leftDrive2;
	m_rightSwim1 = RobotMap::rightDrive1;
	m_rightSwim2 = RobotMap::rightDrive2;
	m_robotSwim = RobotMap::m_robotDrive;
}

double Swim::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	return abs(m_rightSwimEncoder->GetDistance()-m_leftSwimEncoder->GetDistance());
}

void Swim::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	m_leftSwim1->Set(output);
	m_leftSwim2->Set(-output);
	m_rightSwim1->Set(output);
	m_rightSwim2->Set(-output);
}

void Swim::InitDefaultCommand()
{

}

void Swim::Start()
{
	PIDController *pid = GetPIDController();
	pid->Reset();
	pid->SetSetpoint(0);
	pid->Enable();
}
