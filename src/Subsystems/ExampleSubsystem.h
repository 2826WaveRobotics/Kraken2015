#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* m_DIO4;
	DigitalInput* m_DIO5;
	DigitalInput* m_DIO6;
	DigitalInput* m_DIO7;
	DigitalInput* m_DIO8;
	DigitalInput* m_DIO9;

public:
	ExampleSubsystem();
	void InitDefaultCommand();
	bool getDIO4();
	bool getDIO5();
	bool getDIO6();
	bool getDIO7();
	bool getDIO8();
	bool getDIO9();
};

#endif
