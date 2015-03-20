#ifndef Drive_H
#define Drive_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "IMU.h"
#include "AHRS.h"
#include "IMUAdvanced.h"
#include "IMURegisters.h"
#include "AHRSProtocol.h"
#include "IMUProtocol.h"

class Drive: public PIDSubsystem
{

#define ENABLE_IMU
	//#define ENABLE_IMU_ADVANCED
	//#define ENABLE_AHRS

	NetworkTable *table;
#if defined(ENABLE_AHRS)
	AHRS *imu;
#elif defined(ENABLE_IMU_ADVANCED)
	IMUAdvanced *imu;
#else // ENABLE_IMU
	IMU *imu;
#endif
	SerialPort *serial_port;

public:
	Drive();
	double ReturnPIDInput();
	void DisablePID();
	void UsePIDOutput(double output);
	double GetPIDOutput();
	void InitDefaultCommand();
	void MoveStraight(float direction);
	void DriveStraight(double power);
	void MoveDistance(double distance);
	void DriveDistance(double power);
	void Turn(double power);
	void Orient(double degrees);
	double GetLeftEncoder();
	double GetRightEncoder();
	double GetDistanceTraveled();
	double GetLeftDistanceTraveled();
	double GetRightDistanceTraveled();
	void Shift(bool high);
	void DriveWithJoysticks();
	void SetPower(double power);
	void SetSidePower(double left, double right);
	void ResetEncoders();
	void SetYaw(double yaw); // because yaw is measured in Robot for now, we need to import it basically
	double GetYaw();
	void SetPIDs(double p, double i, double d);
	void PIDReset();
	void GyroReset();
	bool first_iteration;
	IMU* getIMU();
	void ZeroYaw();
	void PrintPIDs();
	void SetPIDMode(int mode);


private:
	RobotDrive* m_robotDrive;
	Encoder* m_driveEncoderLeft;
	Encoder* m_driveEncoderRight;
	Solenoid* m_shifter;

	CANTalon* m_left1;
	CANTalon* m_left2;
	CANTalon* m_right1;
	CANTalon* m_right2;

	double m_inchesToDrive;
	double m_distanceDriven;

	double m_throttle;
	double m_turn;

	double m_p;
	double m_i;
	double m_d;

	int m_mode;
};

#endif
