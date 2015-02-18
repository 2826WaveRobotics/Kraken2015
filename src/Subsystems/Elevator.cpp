#include "Elevator.h"
#include "../RobotMap.h"


namespace
{
double MaxVolts = 3.5;
double MinVolts = 0;
double MinLength = lowElevatorPosition;
double MaxLength = highElevatorPosition;

float c_downP = 1.0;
float c_downI = 0.0;
float c_downD = 0.0;

float c_upP = 1.0;
float c_upI = 0.0;
float c_upD = 0.0;

float aVal = 0.1857567;
float bVal = -1.329018;
float cVal = 9.266816;
float dVal = 4.541211;
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
	m_toteLock = RobotMap::toteLocker;
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
	m_elevatorRight->PIDWrite(output);
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
	float centimeters = (dVal + ((aVal - dVal)/(1 + pow((volts/cVal),(bVal)))));
	float inches = .393701 * centimeters;
	return inches;
}

float Elevator::convertInchesToVolts (double inches)
{
	float volts = cVal * ( pow((((aVal-dVal)/(inches-dVal))-1), (1/bVal)));
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

	///////////////////Test for the consistency of the voltage reading//////////////////
	//delay the number of volts
	double test_voltage;
	double test_average = 0;
	double test_mode;
	int test_iteration = 0;
	double test_low_value;
	double test_high_value;
	double test_high_value_max;
	double test_low_value_min;
	double test_variance;

	test_high_value = test_low_value = getCurrentVoltageOfSensor();

	//	for(test_iteration = 0; test_iteration < 500; test_iteration++) // get 500 data points and find mode
	//	{
	//		test_voltage = getCurrentVoltageOfSensor(); // get the voltage to work with
	//		test_sample[test_iteration] = test_voltage; // assign the value to an array for reference later
	//
	//		if(test_voltage > test_high_value){ // assign the high and low points
	//			test_high_value = test_voltage;
	//		}
	//		if(test_voltage < test_low_value){
	//			test_low_value = test_voltage;
	//		}
	//		test_average *= test_iteration; // calculate a new average
	//		test_average += test_voltage;
	//		test_average /= (test_iteration+1);
	//
	//		std::cout << test_voltage << std::endl; // print out the voltage
	//
	//		if(test_iteration > 500-2) // minus 2 to make sure we reach it
	//		{
	//			test_variance = test_high_value - test_low_value; // calculate the max variance during the run of the robot
	//			if(test_variance > test_max_variance){
	//				test_max_variance = test_variance;
	//			}
	//			if(test_high_value > test_high_value_max){ // calculate the high and low values achieved during the run
	//				test_high_value_max = test_high_value;
	//			}
	//			if(test_low_value < test_low_value_min){
	//				test_low_value_min = test_low_value;
	//			}
	//			//sortArray();
	//			//std::cout << test_variance << "\t" << test_max_variance << std::endl;
	//			//test_mode = getMode(test_values); // calculate the mode
	//			//std::cout << "\t\t\t\t\t" << "Test Average: " << test_average << "\t\tMode: " << test_mode << std::endl;
	//
	//		} // end final test
	//		Wait(.0001);
	//	}


	////////////////End Test////////////////

	m_elevatorLeft->Set(-speed);
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

double Elevator::getMode(double input[])
{
	int returnVal = input[0]; // stores element to be returned
	int repeatCount = 0; // counts the record number of repeats
	int prevRepCnt = 0; // temporary count for repeats

	for(int k = 0; k < 500; k++){
		std::cout << input[k] << std::endl;
	}

	for (int i=0; i<500; i++) { // goes through each elem

		for (int j=i; j<500; j++) { // compares to each elem after the first elem

			if (i != j && input[i] == input[j]) { // if matching values
				repeatCount++; // gets the repeat count

				if (repeatCount>=prevRepCnt) { // a higher count of repeats than before
					returnVal=input[i]; // return that element
				}
				prevRepCnt = repeatCount; // Keeps the highest repeat record
			}
			repeatCount=0; // resets repeat Count for next comparison
		}
	}
	std::cout << "Mode: " << returnVal << std::endl;
	return returnVal;

}

void Elevator::sortArray()
{
	bool swapped = true;
	double tempValue;

	for(int i = 0; (i < 500 && swapped == true); i++)
	{
		swapped = false;
		if(test_sample[i] > test_sample[i+1]) // need to swap
		{
			tempValue = test_sample[i];
			test_sample[i] = test_sample[i+1];
			test_sample[i+1] = tempValue;
			swapped = true;
		} // swapping complete
	} // no swaps made, sort complete

	std::cout << "Sorted Values!" << std::endl;
	for(int k = 0; k < 500; k++)
	{
		std::cout << test_sample[k] << std::endl;
	}
}
void Elevator::lockTotes(bool lock = true){
	m_toteLock->Set(lock);
}
