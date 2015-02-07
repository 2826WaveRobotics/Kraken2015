#include "Elevator.h"
#include "../RobotMap.h"

namespace
{
	double MaxVolts = 12;
	double MinVolts = 0;
	double MinLength = lowElevatorPosition;
	double MaxLength = highElevatorPosition;

	float c_downP = 1.0;
	float c_downI = 0.0;
	float c_downD = 0.0;

	float c_upP = 1.0;
	float c_upI = 0.0;
	float c_upD = 0.0;
}




Elevator::Elevator() :
		PIDSubsystem("Elevator", 0.5, 0.0, 0.0)

{
	SetAbsoluteTolerance(0.1);
		GetPIDController()->SetContinuous(false);
		//LiveWindow::GetInstance()->AddActuator("ArmPitchWithPID", "PIDSubsystem Controller", GetPIDController());
		GetPIDController()->SetInputRange(MinVolts, MaxVolts); //range on sensor 0-12 volts
		GetPIDController()->SetOutputRange(-1.0, 1.0); //range on motors
		GetPIDController()->SetAbsoluteTolerance(0.3); //plus or minus this voltage

	m_elevatorLeft = RobotMap::elevatorLeft;
	m_elevatorRight = RobotMap::elevatorRight;
	m_elevatorSensor = RobotMap::elevatorSensor;
}

double Elevator::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
        return m_elevatorSensor->GetAverageVoltage();
}

double Elevator::GetPIDOutput()
{
	return GetPIDController()->Get();
}


void Elevator::UsePIDOutput(double output) {
    output = -output; //Arm motors are inverted

    //Limit the acceleration
//    if(output > 0.8)
//    {
//        output = 0.8;
//    }
//    else if(output < -0.8)
//    {
//        output = -0.8;
//    }

	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);

	m_elevatorLeft->PIDWrite(output);
	m_elevatorRight->PIDWrite(-output);
}

void Elevator::setAbsoluteHeight(double targetHeight)
{

    PIDController *pid = GetPIDController();
    double currentHeight = convertVoltsToInches(getCurrentVoltageOfSensor());

    if(currentHeight<targetHeight)
    {
        //These are DOWN gains

           pid->SetPID(c_downP, c_downI, c_downD);
    }
    else
    {
        //These are UP gains

            pid->SetPID(c_upP, c_upI, c_upD);
        }

    double setVoltage = convertInchesToVolts(targetHeight);

    pid->Reset();
    pid->SetSetpoint(setVoltage); //setpoint is in voltage
    pid->Enable();

}

void Elevator::disablePID()
{
	GetPIDController()->Disable();
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float Elevator::convertVoltsToInches (float volts)
{
	double inches = ((MaxLength - MinLength)/(MaxVolts - MinVolts)) * volts;
	return inches;
}

float Elevator::convertInchesToVolts (double inches)
{
	float volts = ((MaxVolts - MinVolts)/(MaxLength - MinLength)) * inches;
		return volts;
}

float Elevator::getCurrentVoltageOfSensor()
{
	return	m_elevatorSensor->GetVoltage();
}

double Elevator::getCurrentHeight()
{
	return convertVoltsToInches(getCurrentVoltageOfSensor());
}

void Elevator::setElevatorMotors(float speed)
{
	m_elevatorLeft->Set(speed);
	m_elevatorRight->Set(-speed);
}

float Elevator::getCurrentFeedback_LeftMotor()
{
	return m_elevatorLeft->GetOutputCurrent();
}

float Elevator::getCurrentFeedback_RightMotor()
{
	return m_elevatorRight->GetOutputCurrent();
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

