#include "ExampleSubsystem.h"
#include "../RobotMap.h"

ExampleSubsystem::ExampleSubsystem() :
		Subsystem("ExampleSubsystem")
{
	m_DIO4 = RobotMap::DIO4;
	m_DIO5 = RobotMap::DIO5;
	m_DIO6 = RobotMap::DIO6;
	m_DIO7 = RobotMap::DIO7;
	m_DIO8 = RobotMap::DIO8;
	m_DIO9 = RobotMap::DIO9;
}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
bool ExampleSubsystem::getDIO4(){
	return m_DIO4;
}
bool ExampleSubsystem::getDIO5(){
	return m_DIO5;
}
bool ExampleSubsystem::getDIO6(){
	return m_DIO6;
}
bool ExampleSubsystem::getDIO7(){
	return m_DIO7;
}
bool ExampleSubsystem::getDIO8(){
	return m_DIO8;
}
bool ExampleSubsystem::getDIO9(){
	return m_DIO9;
}
