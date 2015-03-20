#include "AutoDrive.h"
#include "../Robot.h"

AutoDrive::AutoDrive(double maxDistance, double power, float direction){
	Requires(Robot::m_drive);
	std::cout << "AutoDrive: Construct" << std::endl;
	m_distance = maxDistance;
	m_power = power;
	m_direction = direction;
	m_distanceTraveled = 0;
}

void AutoDrive::Initialize()
{
	Robot::m_drive->SetPIDMode(mode_straight);
	Robot::m_drive->ResetEncoders();
	//Robot::m_drive->AutoPIDReset();
//	Robot::m_drive->SetPIDs(.0246094, 0, .0742188);
	Robot::m_drive->SetPIDs(.035, 0, .08);
	Robot::m_drive->MoveStraight(m_direction);
}

void AutoDrive::Execute()
{
	Robot::m_drive->DriveStraight(m_power);
}

bool AutoDrive::IsFinished()
{
	m_distanceTraveled = Robot::m_drive->GetDistanceTraveled();
//	std::cout << "Distance: " << m_distance << "\tTraveled: " <<
//			m_distanceTraveled << "\tPower: " << m_power << std::endl;

	if(m_power > 0 && m_distanceTraveled > m_distance){
		return true;
	}
	else if(m_power < 0 && m_distanceTraveled < m_distance){
		return true;
	}
	else if(m_power == 0){
		return true;
	}
	else{
		return false; // return false, allowing us to destroy this command when a new instance starts
	}
}

void AutoDrive::End()
{
	std::cout << "AutoDrive: End" << std::endl;
	Robot::m_drive->SetSidePower(0,0); // stop moving
	//m_power = 0; // set the power to zero, so the correction keeps running
	//Robot::m_drive->DriveStraight(m_power);
}

void AutoDrive::Interrupted()
{
	End();
}
