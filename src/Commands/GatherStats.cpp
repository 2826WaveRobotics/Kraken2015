#include "GatherStats.h"
GatherStats::GatherStats()
{

}

void GatherStats::Initialize()
{
std::cout << "GatherStatistics: Intitialize" << std::endl;
}


void GatherStats::Execute()
{
	///////////////////Test for the consistency of the voltage reading//////////////////
	//delay the number of volts
	double test_voltage;
	double test_average = 0;
	int test_iteration = 0;
	double test_low_value;
	double test_high_value;
	double test_high_value_max;
	double test_low_value_min;
	double test_variance;

	test_high_value = test_low_value = Robot::m_elevator->getCurrentVoltageOfSensor();

	for(test_iteration = 0; test_iteration < 100000; test_iteration++)
	{
		test_voltage = Robot::m_elevator->getCurrentVoltageOfSensor();

		if(test_voltage > test_high_value){ // assign the high and low points
			test_high_value = test_voltage;
		}
		if(test_voltage < test_low_value){
			test_low_value = test_voltage;
		}
		test_average *= test_iteration;
		test_average += test_voltage;
		test_average /= (test_iteration+1);

		if(test_iteration > 99998)
		{
			test_variance = test_high_value - test_low_value;
			if(test_variance > Robot::m_elevator->test_max_variance){
				Robot::m_elevator->test_max_variance = test_variance;
			}
			if(test_high_value > test_high_value_max){
				test_high_value_max = test_high_value;
			}
			if(test_low_value < test_low_value_min){
				test_low_value_min = test_low_value;
			}
			std::cout << test_variance << "\t" << Robot::m_elevator->test_max_variance << std::endl;
		}
	}
	////////////////End Test////////////////
}

bool GatherStats::IsFinished()
{
	return true;
}

void GatherStats::End()
{
	std::cout << "Gathering Statistics Has Ended" << std::endl;
}

void GatherStats::Interrupted()
{
	End();
}
