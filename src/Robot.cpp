#include "Robot.h"

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Auto.h"
#include "CommandBase.h"
#include "OI.h"
#include "WaveConstants.h"
#include "RobotMap.h"

using namespace std;

OI* Robot::oi = 0;
Drive* Robot::m_drive = 0;
Elevator* Robot::m_elevator = 0;
Recycler* Robot::m_recycler = 0;
Intake* Robot::m_intake = 0;
BinJuggler* Robot::m_binJuggler = 0;
CompressorSubsystem* Robot::m_compressor = 0;

void Robot::RobotInit()
{
	RobotMap::init();

	CommandBase::init();
	lw = LiveWindow::GetInstance();
	m_drive= new Drive();
	m_elevator = new Elevator();
	oi = new OI();
	m_recycler = new Recycler();
	autonomousCommand = new Auto();
	m_intake= new Intake();
	m_binJuggler= new BinJuggler();
	m_compressor= new CompressorSubsystem();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
	m_compressor->Stop();
	Wait(0.01);

	if(oi->GetDebugJoystickButton(16)){ // change back to 17 later
		cout << m_intake->IsFrontSensorTripped();
		cout << m_intake->IsAligned();
		cout << m_recycler->isLowerSensorTripped();
		cout << m_recycler->isUpperSensorTripped() << "\t";
		cout << m_elevator->getCurrentVoltageOfSensor() << "\t\t";
		cout << m_elevator->convertVoltsToInches(m_elevator->getCurrentVoltageOfSensor()) << "\t";
		cout << m_drive->GetLeftEncoder() << "\t";
		cout << m_drive->GetRightEncoder() << "\t";
		cout << endl;
	}
	//	else{ // For reading values from controller for PIDs
	//		double c_upP, c_downP, c_upI, c_downI, c_upD, c_downD;
	//		if(Robot::oi->GetDebugJoystickButton(17)){ //
	//			//put max value in front of Robot::oi
	//			c_upP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//			c_downP = 6*(Robot::oi->getDebugJoystick()->GetRawAxis(4) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//			c_upI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//			c_downI = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(2) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//			c_upD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//			c_downD = .5*(Robot::oi->getDebugJoystick()->GetRawAxis(3) / 2 + .5); // joystick from -1 to 1, then range cut down to -.5 to .5, and brought up to 0 to 1
	//		}
	//		else{
	//			c_upP = 2;
	//			c_downP = 2;
	//			c_upI = 0;
	//			c_downI = 0;
	//			c_upD = 0;
	//			c_downD = 0;
	//		}
	//
	//		std::cout << "Pup: " << c_upP << "\tPdown: " << c_downP << "\tIup: " << c_upI << "\tIdown: " << c_downI << "\tDup: " << c_upD << "\tDdown: " << c_downD << std::endl;
	//
	//	}
	double leftCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(2) / 5);
	double rightCoef = 1 - (Robot::oi->getDebugJoystick()->GetRawAxis(3) / 5);
	//std::cout << "Left: " << leftCoef << "\tRight: " << rightCoef << std::endl;
}

void Robot::AutonomousInit()
{
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
	m_compressor->Start();
}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	if (autonomousCommand != NULL){
		autonomousCommand->Cancel();
	}
	m_compressor->Start();
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
	oi->checkInput(); // runs through a function to check all the used buttons and joysticks

	if(oi->GetDebugJoystickButton(16)){
		//		cout << m_intake->IsFrontSensorTripped();
		//		cout << m_intake->IsAligned();
		//		cout << m_recycler->isLowerSensorTripped();
		//		cout << m_recycler->isUpperSensorTripped() << "\t";
		//		cout << m_elevator->getCurrentVoltageOfSensor() << "\t";
		//		cout << m_drive->GetLeftEncoder() << "\t";
		//		cout << m_drive->GetRightEncoder() << "\t";
		//cout << endl;
		double leftLoad = m_elevator->getCurrentFeedback_LeftMotor();
		double rightLoad = m_elevator->getCurrentFeedback_RightMotor();
		double averageLoad = (leftLoad + rightLoad) / 2;
		std::cout << "Average Load: " << averageLoad << "\tLeft: " << leftLoad << "\tRight: " << rightLoad << std::endl;
	}



	Wait(0.01);
}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

