#ifndef SYSTEM_TEST_COMMAND_H
#define SYSTEM_TEST_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"


enum
{
	Test_leftDrive1 = 0,
	Test_leftDrive2,
	Test_rightDrive1,
	Test_rightDrive2 ,
	Test_elevatorLeft ,
	Test_elevatorRight ,
	Test_trackArm ,
	Test_frontIntakeLeft,
	Test_frontIntakeRight,
	Test_rearIntake,
	Test_shifter,
	Test_jugglerLift,
	Test_leftLock,
	Test_rightLock,
	Test_leftGrab,
	Test_rightGrab,
	//Test_toteConstrictor
};



class SystemTestCommand: public CommandBase
{
public:
	SystemTestCommand(int SystemTest);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int m_TestToRun;
};


#endif
