#include "AutoCurve.h"
#include "Robot.h"

AutoCurve::AutoCurve(double angle)
{
	Requires(Robot::m_drive);
	m_angle = angle;
}

void AutoCurve::Initialize()
{
	Robot::m_drive->SetPIDMode(mode_straight);
	Robot::m_drive->ResetEncoders();
	SetTimeout(5);
	Robot::m_drive->Orient(m_angle);
	Robot::m_drive->SetPIDs(0.0152344, 0, 0); //[for swapping wheels] (.03,0,0);
}

void AutoCurve::Execute()
{
	std::cout << "Distance Left: " << fabs(Robot::m_drive->GetLeftDistanceTraveled()) << "\tRight: "
			<< fabs(Robot::m_drive->GetRightDistanceTraveled()) << std::endl;

	//Robot::m_drive->Turn(0);
	double correction = Robot::m_drive->GetPIDOutput();
	double correctedLeftPower =  0 + correction;
	double correctedRightPower = 0 - correction;
	double limit = .6; // [swapping wheels] = 1;
	if(correctedLeftPower > limit){
		correctedLeftPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedLeftPower = -limit;
	}
	if(correctedRightPower > limit){
		correctedRightPower = limit;
	}
	else if(correctedRightPower < -limit){
		correctedRightPower = -limit;
	}
	Robot::m_drive->SetSidePower(correctedLeftPower, correctedRightPower);
	double degreesOff = fabs(Robot::m_drive->GetSetpoint() - Robot::m_drive->GetYaw());
	std::cout << "Correction: " << correction << "\tLeft: " <<
			correctedLeftPower << "\tRight: " << correctedRightPower << "\tYaw: "
			<< Robot::m_drive->GetYaw() << "\tSetpoint: " << Robot::m_drive->GetSetpoint() <<
			"\tOff By: " << degreesOff << std::endl;

}

bool AutoCurve::IsFinished()
{
	double facing = Robot::m_drive->GetYaw();
	std::cout << "Yaw: " << facing << std::endl;
	if(facing > m_angle - 5 && facing < m_angle + 5){
		Robot::m_drive->SetSidePower(-1,1);
		return true;
	}
	else{
		return false;
	}
}

void AutoCurve::End()
{
	//Robot::m_drive->EnableAutoDrive(true);
	Robot::m_drive->SetSidePower(0,0); // stop the wheels
}

void AutoCurve::Interrupted()
{
	End();
}
