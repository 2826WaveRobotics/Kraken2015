#ifndef PID_DRIVE_H
#define PID_DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PIDDrive: public PIDSubsystem
{
public:
	PIDDrive();
	void InitDefaultCommand();
	void DriveWithJoysticks(float left, float right);
	void ShiftGear(bool highGear);
	void setDriveOutputPID();
	void setDistance(double inches);
	float getPIDOutput();
	double getCurrentDistance();
	void displayEncoders();

	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double);


private:
	RobotDrive* m_robotDrive;
	Encoder* m_driveEncoderLeft;
	Encoder* m_driveEncoderRight;
	Solenoid* m_shifter;


	double m_inchesToDrive;
	double m_distanceDriven;
};

#endif
