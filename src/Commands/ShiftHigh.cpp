#include "ShiftHigh.h"

ShiftHigh::ShiftHigh()
{

}

void ShiftHigh::Initialize()
{
	std::cout << "Shift High: Initialize " << std::endl;
}

void ShiftHigh::Execute()
{
	if(m_shiftState == true){
		std::cout << "Shift State: true" << std::endl;
		m_shiftState = false;
	}
	else if(m_shiftState == false){
		std::cout << "Shift State: false" << std::endl;
		m_shiftState = true;
	}
}

bool ShiftHigh::IsFinished()
{
	std::cout << "Shift High is Finished? " << std::endl;
	return true;
}

void ShiftHigh::End()
{
	std::cout << "Shift High: End " << std::endl;
}

void ShiftHigh::Interrupted()
{
	std::cout << "Shift High: Interrupted" << std::endl;
}
