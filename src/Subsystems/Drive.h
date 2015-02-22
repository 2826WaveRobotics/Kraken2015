#ifndef DRIVE_H
#define DRIVE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "LeftPID.h"
#include "RightPID.h"

class Drive: public Subsystem
{
public:
	Drive();
	void InitDefaultCommand();
	void DriveWithJoysticks(float left, float right);
	void ShiftGear(bool highGear);
	double GetLeftEncoder();
	double GetRightEncoder();

	//PID stuff
	void SetDriveDistance(double distance);
	double GetDistanceTravelled();

	//PID Controller Wrapper Functions
	void Enable();
	void Disable();
	void Reset();
	void SetEncodersContinuous(bool cont);
	void SetDriveSetpoint(double setpoint);
	void SetLeftSetpoint(double setpoint);
	void SetRightSetpoint(double setpoint);
	void SetDrivePID(double p, double i, double d);

private:
	RobotDrive* m_robotDrive;
	Encoder* m_driveEncoderLeft;
	Encoder* m_driveEncoderRight;
	Solenoid* m_shifter;

	LeftPID* m_leftPID;
	RightPID* m_rightPID;

	double m_inchesToDrive;
	double m_distanceDriven;
};

#endif
