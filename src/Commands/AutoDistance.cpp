#include "AutoDistance.h"
#include "../Robot.h"

//EXACT SAME AS AUTODRIVE but with the addition of checkPower in Execute()

AutoDistance::AutoDistance(double maxDistance, double maxPower, double minPower, float direction){
	Requires(Robot::m_drive);
	std::cout << "AutoDistance: Construct" << std::endl;
	m_distance = maxDistance;
	m_maxPower = maxPower;
	m_direction = direction;
	m_distanceTraveled = 0;
	m_minPower = minPower;
	m_specialCase = false;

	m_distanceTolerance = .5;
	m_velocityTolerance = 2;
	m_midpointMultiplier = .8;
}
AutoDistance::AutoDistance(double maxDistance, double maxPower, double minPower, float direction,
		bool special, double distanceTolerance, double velocityTolerance, double midpointMultiplier){
	Requires(Robot::m_drive);
	std::cout << "AutoDistance: Construct" << std::endl;
	m_distance = maxDistance;
	m_maxPower = maxPower;
	m_direction = direction;
	m_distanceTraveled = 0;
	m_minPower = minPower;
	m_specialCase = true;

	m_distanceTolerance = distanceTolerance;
	m_velocityTolerance = velocityTolerance;
	m_midpointMultiplier = midpointMultiplier;
}

void AutoDistance::Initialize()
{
	Robot::m_drive->SetPIDMode(mode_straight);
	Robot::m_drive->ResetEncoders();
	//Robot::m_drive->AutoPIDReset();
	//	Robot::m_drive->SetPIDs(.0246094, 0, .0742188);
	Robot::m_drive->SetPIDs(.055, 0, .08); // .035
	Robot::m_drive->MoveStraight(m_direction); //sets up the PID for moving straight
}

void AutoDistance::Execute()
{
	std::cout << "AutoDistance: m_distance = " << m_distance << std::endl;
	double m_modPower = Robot::m_drive->CheckPower(m_maxPower, m_minPower, m_distance, m_midpointMultiplier); // get the max power allowed to move (basically P)
	Robot::m_drive->DriveStraight(m_modPower); //sets the correction based on degrees off the angle
}

bool AutoDistance::IsFinished()
{
	m_distanceTraveled = Robot::m_drive->GetDistanceTraveled();
	std::cout << "Distance to Go: " << m_distance << "\tLeft: " << Robot::m_drive->GetLeftDistanceTraveled() <<
			"\tRight: " << Robot::m_drive->GetRightDistanceTraveled() << "\tPower: " << m_power << std::endl;
	m_velocity = Robot::m_drive->GetVelocity();

	//if(fabs(m_distanceTraveled) > fabs(m_distance)){
	//	return true;
	//}
	/*	if(m_power > 0 && m_distanceTraveled > m_distance){
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
	 */

	if((fabs(fabs(m_distanceTraveled)-fabs(m_distance))<m_distanceTolerance)&&(fabs(m_velocity)<m_velocityTolerance))
	{
		return true;
	}
	else
	{
		return false; // return false, allowing us to destroy this command when a new instance starts
	}

}

void AutoDistance::End()
{
	std::cout << "AutoDistance: End" << std::endl;
	Robot::m_drive->SetSidePower(0,0); // stop moving
	//m_power = 0; // set the power to zero, so the correction keeps running
	//Robot::m_drive->DriveStraight(m_power);
}

void AutoDistance::Interrupted()
{
	End();
}
