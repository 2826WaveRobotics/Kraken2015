#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drive: public PIDSubsystem
{
public:
	Drive();
	void InitDefaultCommand();
	void DriveWithJoysticks(float left, float right);
	void ShiftGear(bool highGear);
	void setDriveOutputPID();
	void setDistance(double inches);
	float getPIDOutput();
	double getCurrentDistance();


	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double);


private:
	RobotDrive* m_robotDrive;
	Encoder* m_driveEncoderLeft;
	Encoder* m_driveEncoderRight;

	double m_inchesToDrive;
	double m_distanceDriven;
};

#endif
