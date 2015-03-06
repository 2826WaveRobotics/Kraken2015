#include "Elevator.h"
#include "../RobotMap.h"
#include "../Robot.h"

namespace
{
double MaxVolts = Elevator_UpperVolts;
double MinVolts = Elevator_LowerVolts;
//double MinLength = lowElevatorPosition;
//double MaxLength = highElevatorPosition;

float c_downP = 2.0; // PID VALUES BEING SET IN setAbsoluteHeight for now, to utilize joysticks to test
float c_downI = 0.0;
float c_downD = 0.0;

float c_upP = 2.0;
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
	GetPIDController()->SetAbsoluteTolerance(elevatorTolerance); //plus or minus this voltage

	m_elevatorLeft = RobotMap::elevatorLeft;
	m_elevatorRight = RobotMap::elevatorRight;
	m_elevatorSensor = RobotMap::elevatorSensor;
	m_toteLock = RobotMap::toteLocker;
}

double Elevator::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	//	return m_elevatorSensor->GetAverageVoltage();
	return m_elevatorSensor->GetVoltage();
}

double Elevator::GetPIDOutput()
{
	//std::cout << "ELevator::GetPIDOutput() -- returning " << GetPIDController()->Get() << std::endl;
	return GetPIDController()->Get();
}


void Elevator::UsePIDOutput(double output) {
	//Enforce virtual limits
	output=checkSoftStops(output, false);

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

	//std::cout << "ELevator::UsePIDOutput() -- " << -output << std::endl;
	m_elevatorLeft->PIDWrite(output);
	m_elevatorRight->PIDWrite(output);
}

void Elevator::setAbsoluteHeight(double targetHeight) // target height is in inches
{
	PIDController *pid = GetPIDController();
	double currentHeight = convertVoltsToInches(getCurrentVoltageOfSensor()); // turning the voltage reading into a usable inch value

	if(Robot::oi->GetDebugJoystickButton(17)){ //
		//put max value in front of Robot::oi
		c_upP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
		c_downP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
		c_upI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
		c_downI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
		c_upD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
		c_downD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	}
	else{
		c_upP = 1;
		c_downP = 1;
		c_upI = 0;
		c_downI = 0;
		c_upD = 0;
		c_downD = 0;
	}

	//std::cout << "\n\nPup: " << c_upP << "\tPdown: " << c_downP << "\tIup: " << c_upI <<
			//"\tIdown: " << c_downI << "\tDup: " << c_upD << "\tDdown: " << c_downD << "\n\n" << std::endl;

	if(currentHeight < targetHeight)
	{
		//These are UP gains
		pid->SetPID(c_upP, c_upI, c_upD);
	}
	else
	{
		//These are DOWN gains
		pid->SetPID(c_downP, c_downI, c_downD);
	}

	double setVoltage = convertInchesToVolts(targetHeight);

	pid->Disable();
	pid->Reset();
	pid->SetSetpoint(setVoltage); //setpoint is in voltage
	pid->Enable();

}

void Elevator::disablePID()
{
	std::cout << "ELevator::DisablePID()" << std::endl;
	GetPIDController()->Disable();
}

void Elevator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

float Elevator::convertVoltsToInches (float volts)
{
	float inches = 6.379 * volts + 3.603;
	return inches;
	std::cout << "inches" << inches << std::endl;
}

float Elevator::convertInchesToVolts (double inches)
{
	float volts = (inches - 3.603) / 6.379;
	return volts;
}

float Elevator::getCurrentVoltageOfSensor()
{
	return	m_elevatorSensor->GetVoltage();
}

double Elevator::getCurrentHeight()
{
	double negative = convertVoltsToInches(getCurrentVoltageOfSensor());
	double inches = 28 - negative;
	//	std::cout << "Inches: " << inches << std::endl;
	return inches;
}

void Elevator::setElevatorMotors(float speed)
{
	/*	if(speed>=0 && getCurrentHeight() >= MaxLength)
	{
		speed = 0;
	}
 if(speed<=0 && getCurrentHeight() <= MinLength)
	{
		speed = 0;
	}
	 */
	std::cout << "Elevator Speed: " << speed << std::endl;
	speed=checkSoftStops(speed, true);

	m_elevatorLeft->Set(-speed);
	m_elevatorRight->Set(-speed);
}

double Elevator::checkSoftStops(double desiredOutput, bool invertedOutput)
{
	//Up is negative speed, Down is positive speed
	double currentVolts = getCurrentVoltageOfSensor();
	double currentHeight = convertVoltsToInches(currentVolts);
	if(invertedOutput)
	{
		if((currentHeight > Elevator_UpperStop) && (desiredOutput < 0))
		{
			//prevent Up movement
			desiredOutput = 0;
		}
		else if((currentHeight < Elevator_LowerStop) && desiredOutput > 0)
		{
			//prevent Down movement
			desiredOutput = 0;
		}
	}
	else
	{
		if((currentHeight > Elevator_UpperStop) && (desiredOutput > 0))
		{
			//prevent Up movement
			desiredOutput = 0;
		}
		else if((currentHeight < Elevator_LowerStop) && desiredOutput < 0)
		{
			//prevent Down movement
			desiredOutput = 0;
		}
	}
	return desiredOutput;
}

float Elevator::getCurrentFeedback_LeftMotor()
{
	return m_elevatorLeft->GetOutputCurrent();
}

float Elevator::getCurrentFeedback_RightMotor()
{
	return m_elevatorRight->GetOutputCurrent();
}

void Elevator::lockTotes(bool lock){
	m_toteLock->Set(lock);
}
void Elevator::CalculateTotes(){

}
void Elevator::SetTotes(int totes){
	m_numOfTotes = totes;
}
int Elevator::GetTotes(){
	return m_numOfTotes;
}
