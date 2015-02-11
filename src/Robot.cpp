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
Swim* Robot::m_swim = 0;

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
	m_swim = new Swim();


}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
	m_compressor->Stop();
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
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
	//m_compressor->Start();
	std::cout << "Message" << std::endl;

	//test
	m_elevator->test_max_variance = 0;
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();

	bool param = oi->getDriverJoystick()->GetRawAxis(3)>0.75 ? true : false;
	m_drive->ShiftGear(param);

	m_drive->DriveWithJoysticks(oi->getDriverJoystick()->GetRawAxis(1), oi->getDriverJoystick()->GetRawAxis(4));

//	m_intake->SetFrontIntake(-oi->getOperatorJoystick()->GetRawAxis(1));
//	m_intake->SetRearIntake(oi->getOperatorJoystick()->GetRawAxis(1));

	m_elevator->setElevatorMotors(oi->getOperatorJoystick()->GetRawAxis(1));

	m_recycler->SetRecycleMotors(oi->getOperatorJoystick()->GetRawAxis(5));

	//m_drive->displayEncoders();

	Wait(0.01);
}

void Robot::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Robot);

