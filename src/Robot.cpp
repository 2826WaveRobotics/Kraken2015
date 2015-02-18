#include "Robot.h"

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
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
	autonomousCommand = new ExampleCommand();
	m_intake= new Intake();
	m_binJuggler= new BinJuggler();
	m_compressor= new CompressorSubsystem();
}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
	m_compressor->Stop();
	Wait(0.01);

	if(oi->GetDebugJoystickButton(16)){
		cout << m_intake->IsFrontSensorTripped();
		cout << m_intake->IsRearSensorTripped();
		cout << m_recycler->isLowerSensorTripped();
		cout << m_recycler->isUpperSensorTripped() << "\t";
		cout << m_elevator->getCurrentVoltageOfSensor() << "\t";
		m_drive->displayEncoders();
		cout << endl;
	}
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

	//test
	m_elevator->test_max_variance = 0;

}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
	oi->checkInput(); // runs through a function to check all the used buttons and joysticks

	if(oi->GetDebugJoystickButton(16)){
		cout << m_intake->IsFrontSensorTripped();
		cout << m_intake->IsRearSensorTripped();
		cout << m_recycler->isLowerSensorTripped();
		cout << m_recycler->isUpperSensorTripped() << "\t";
		cout << m_elevator->getCurrentVoltageOfSensor() << "\t";
		m_drive->displayEncoders();
		cout << endl;
	}

	Wait(0.005);
}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

