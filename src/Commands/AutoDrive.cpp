#include "AutoDrive.h"
#include "../Robot.h"
/**
 * This Command allows you to drive a set distance at a set power, but has additional tools for knowing
 * when to stop. Also, it uses the SetCoefPower from Drive to ensure that it drives straight.
 * It will automatically stop when it has reached a NEW tote. This is determined by a series of
 * "waiting" conditions. It will start looking for a new tote ONLY when the intake is clear, and HAS BEEN CLEAR
 * FOR .05 SECONDS! This stops the intake from tripping when the tote falls back down into it. This was discovered
 * when the elevator would life the tote just high enough to "clear" the intake, and then allowed it to fall back
 * down a fraction of an inch. This was interpreted as a new tote.
 */

//Setting the distance does not currently work
AutoDrive::AutoDrive(double minDistance, double power, double bearing)
{
	std::cout << "AutoDrive: Construct" << std::endl;
	m_minDistanceToDrive = minDistance;
	m_maxDistanceToDrive = minDistance + 20; // the max distance is 20 inches above the minimum distance
	m_power = -power;
	m_bearing = bearing;
}

void AutoDrive::Initialize()
{
	std::cout << "AutoDrive: Initialize" << std::endl;
	Robot::m_drive->SetCoefPower(m_power); // Start moving right away
	m_intakeCleared = false; // we start out assuming that the intake has not been cleared
	m_ImWaitingForATote = false; // we are not looking for a tote right away
	m_timer.Reset();
	m_timer.Start(); // start the timer right away, so we can check it
	m_checkingTime = false; // we are not checking time right away
	m_WeFoundTote = false; // we start out not having found our tote
	m_farEnough = false;
	Robot::m_drive->ResetEncoders(); // reset the encoders, so we can calculate driving from this point
}

void AutoDrive::Execute()
{
	std::cout << "AutoDrive: Execute" << std::endl;
	bool toteInIntake = Robot::m_intake->IsFrontSensorTripped();
	m_distanceTravelled = Robot::m_drive->GetDistanceTravelled();

	//Checking if we have a tote (besides the one we started moving with) in the intake
	if(toteInIntake == false && m_checkingTime == false){ // only reset and start the timer when we are not checking the timer (not waiting for it to complete)
		std::cout << "toteInIntake = false | m_checkingTime = false" << std::endl;
		std::cout << "We don't have a tote in the intake, and we aren't counting time, so we start counting time" << std::endl;
		m_checkingTime = true; // stop resetting the time when we are waiting for it
		m_timer.Reset();
		m_timer.Start(); // reset and restart the timer
	}
	if(toteInIntake == true && m_ImWaitingForATote == false){ // if a tote appears in the intake, and we are not looking for one (it fell back down)
		std::cout << "toteInIntake = true | m_ImWaitingForATote = false" << std::endl;
		std::cout << "We have a tote in the intake, but we aren't waiting for one. So we reject the time" << std::endl;
		m_checkingTime = false; // if a tote appears in our intake, we stop checking time, and continue resetting it
	}

	if(m_timer.HasPeriodPassed(.05) && toteInIntake == false && m_distanceTravelled > m_minDistanceToDrive){ // if .05s have passed and the intake is clear
		std::cout << "m_timer > .05 | toteInIntake = false" << std::endl;
		std::cout << "The time has passed, and we don't have a tote in the intake. We are looking for a tote" << std::endl;
		m_ImWaitingForATote = true; // we start looking for a new tote
	}

	if(m_ImWaitingForATote == true && toteInIntake == true){ // We were looking for a tote, and we found one
		std::cout << "m_ImWaitingForATote = true | toteInIntake = true" << std::endl;
		std::cout << "We are no longer waiting for a tote, because we found one!" << std::endl;
		m_ImWaitingForATote = false; // we are no longer looking for a tote
		m_WeFoundTote = true; // we found a tote (useful for checking IsFinished())
	}

	//checking if we have driven far enough

	if(m_distanceTravelled > m_maxDistanceToDrive){ // we have driven far enough
		std::cout << "Distance Traveled is Bigger than the Target | m_distanceTravelled: " << m_distanceTravelled <<
				"\tm_maxDistanceToDrive: " << m_maxDistanceToDrive << std::endl;
		std::cout << "We Are Far Enough" << std::endl;
		m_farEnough = true;
	}

}

bool AutoDrive::IsFinished()
{
	std::cout << "AutoDrive: IsFinished?" << std::endl;
	if(m_WeFoundTote == true){ // we found a tote
		std::cout << "We have found a tote!" << std::endl;
		return true;
	}
	else if(m_farEnough == true){ // we have driven far enough
		std::cout << "We have gone far enough, are we are ending" << std::endl;
		return true;
	}
	else{
		return false;
	}
}

void AutoDrive::End()
{
	std::cout << "AutoDrive: End" << std::endl;
	Robot::m_drive->SetCoefPower(0); // stop moving
}

void AutoDrive::Interrupted()
{
	std::cout << "AutoDrive: Interrupted" << std::endl;
	//End();
}

void AutoDrive::CalculateTurn(){
	//use this space for calculating the power to each of the sides during the turn
}
