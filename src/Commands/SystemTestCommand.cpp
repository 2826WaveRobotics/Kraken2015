#include "SystemTestCommand.h"
#include "RobotMap.h"

SystemTestCommand::SystemTestCommand(int SystemTest)
{
	m_TestToRun = SystemTest;
}

void SystemTestCommand::Initialize()
{
	switch(m_TestToRun)
	{
	case Test_leftDrive1:
		 RobotMap::leftDrive1->Set(.5);
		break;
	case Test_leftDrive2:
		RobotMap::leftDrive2->Set(.5);
		break;
	case Test_rightDrive1:
		RobotMap::rightDrive1->Set(.5);
		break;
	case Test_rightDrive2:
		RobotMap::rightDrive2->Set(.5);
		break;
	case Test_elevatorLeft:
		std::cout << "Testing Left Elevator Motor" << std::endl;
		RobotMap::elevatorLeft->Set(.5);
		break;
	case Test_elevatorRight:
		std::cout << "Testing Right Elevator Motor" << std::endl;
		RobotMap::elevatorRight->Set(.5);
		break;
	case Test_trackArm:
		RobotMap::trackArm->Set(.5);
		break;
	case Test_frontIntakeLeft:
		RobotMap::frontIntakeLeft->Set(.5);
		break;
	case Test_frontIntakeRight:
		RobotMap::frontIntakeRight->Set(.5);
		break;
	case Test_rearIntake:
		RobotMap::rearIntake->Set(.5);
		break;
	case Test_shifter:
		RobotMap::shifter->Set(true);
		break;
	case Test_jugglerLift:
		RobotMap::jugglerCylinder->Set(true);
		break;
	case Test_leftLock:
		RobotMap::leftLock->Set(true);
		break;
	case Test_rightLock:
		RobotMap::rightLock->Set(true);
		break;
	case Test_leftGrab:
		RobotMap::leftGrab->Set(true);
		break;
	case Test_rightGrab:
		RobotMap::rightGrab->Set(true);
		break;
//	case Test_toteConstrictor:
	}
}

void SystemTestCommand::Execute()
{

}

bool SystemTestCommand::IsFinished()
{
	//bool isDone = false;

//	switch(m_TestToRun)
//	{
//		case Test_leftDrive1:
//			if(oi->getDebugJoystick2()->GetRawButton(1) == 0);
//			{
//				isDone = true;
//			}
//			break;
//		case Test_leftDrive2:
//			break;
//		case Test_rightDrive1:
//			break;
//		case Test_rightDrive2:
//			break;
//		case Test_elevatorLeft:
//			break;
//		case Test_elevatorRight:
//			break;
//		case Test_trackArm:
//			break;
//		case Test_frontIntakeLeft:
//			break;
//		case Test_frontIntakeRight:
//			break;
//		case Test_rearIntake:
//			break;
//		case Test_shifter:
//			break;
//		case Test_jugglerLift:
//			break;
//		case Test_leftLock:
//			break;
//		case Test_rightLock:
//			break;
//		case Test_leftGrab:
//			break;
//		case Test_rightGrab:
//			break;
////		case Test_toteConstrictor:
//	}//switch
	//return isDone;
	return true;
}

void SystemTestCommand::End()
{
	switch(m_TestToRun)
		{
		case Test_leftDrive1:
			RobotMap::leftDrive1->Set(0);
			break;
		case Test_leftDrive2:
			break;
		case Test_rightDrive1:
			break;
		case Test_rightDrive2:
			break;
		case Test_elevatorLeft:
			break;
		case Test_elevatorRight:
			break;
		case Test_trackArm:
			break;
		case Test_frontIntakeLeft:
			break;
		case Test_frontIntakeRight:
			break;
		case Test_rearIntake:
			break;
		case Test_shifter:
			break;
		case Test_jugglerLift:
			break;
		case Test_leftLock:
			break;
		case Test_rightLock:
			break;
		case Test_leftGrab:
			break;
		case Test_rightGrab:
			break;
//		case Test_toteConstrictor:
		}
}

void SystemTestCommand::Interrupted()
{
	End();
}
