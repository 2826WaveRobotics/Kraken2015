#include "Robot.h"

#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/Auto.h"
#include "CommandBase.h"
#include "OI.h"
#include "WaveConstants.h"
#include "RobotMap.h"
#include "Commands/LoadMagazine.h"
#include "Commands/AutoMode_DoNothing.h"
#include "Commands/AutoMode_NoBack.h"
#include "Commands/AutoMode_ShootTotes.h"

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
	//Drive:
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

	autoChooser = new SendableChooser();
	//autoChooser->AddObject("AutoMode", new Auto());
	autoChooser->AddObject("Default - Do Nothing",  new AutoMode_DoNothing());
	autoChooser->AddObject("Win Mode", new Auto());
	autoChooser->AddObject("No Backing", new AutoMode_NoBack());
	autoChooser->AddDefault("ShootTotes", new AutoMode_ShootTotes());
	SmartDashboard::PutData("Auto Modes", autoChooser);

}

void Robot::DisabledInit(){ // things to do when we start disabled
	//m_binJuggler->loadSelection(Bin_LiftCylinder, true);
}
void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
	m_compressor->Stop();

	if(oi->GetDebugJoystickButton(16)){ // change back to 17 later
		double _p = ((Robot::oi->getDebugJoystick()->GetRawAxis(4) + 1) / 2) * .05;
		double _i = ((Robot::oi->getDebugJoystick()->GetRawAxis(2) + 1) / 2) * .05;
		double _d = ((Robot::oi->getDebugJoystick()->GetRawAxis(3) + 1) / 2) * .05;
		std::cout << "P: " << _p << "\tI: " << _i << "\tD: " << _d << std::endl;
	}
	else{

//		std::cout << "RecLow: " << Robot::m_recycler->isLowerSensorTripped() <<
//				"\tRecHigh: " << Robot::m_recycler->isUpperSensorTripped() <<
//				"\tBinSensed: " << Robot::m_recycler->isBinSensed() <<
//				"\tIntake: " << Robot::m_intake->IsFrontSensorTripped() <<
//				"\tLeft: " << Robot::m_drive->GetLeftDistanceTraveled() <<
//				"\tRight: " << Robot::m_drive->GetRightDistanceTraveled() << std::endl;
		//std::cout << "Velocity: " << m_drive->GetVelocity() << std::endl;
	}
	//std::cout << "Elevator Height: " << m_elevator->getCurrentHeight() <<
		//" inches \t\tVoltage: " << m_elevator->getCurrentVoltageOfSensor() << std::endl;

	//std::cout << "Auto Bin Sensor:" << RobotMap::autoBinSensor->Get() << std::endl;

	Wait(0.01);
}

void Robot::AutonomousInit()
{
	m_drive->ZeroYaw();
	m_drive->MoveStraight(0);
	m_drive->Shift(false); // low gear
	m_binJuggler->loadSelection(Bin_LeftLock,false);


	//	double _p = ((oi->getDebugJoystick()->GetRawAxis(4) + 1) / 2)*.3; // .125
	//	double _i = ((oi->getDebugJoystick()->GetRawAxis(2) + 1) / 2)*.0; // we are not using I
	//	double _d = ((oi->getDebugJoystick()->GetRawAxis(3) + 1) / 2)*.5; // .25
	//	Robot::m_drive->SetPIDs(_p,_i,_d);

	//autonomousCommand = new Auto();
	autonomousCommand = (Command *) autoChooser->GetSelected();

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
	m_compressor->Start();
}
//Upper Sensor Tripped
void Robot::AutonomousPeriodic()
{
	m_drive->PrintPIDs();
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	if (autonomousCommand != NULL){
		autonomousCommand->Cancel();
	}
	m_compressor->Start();
	// things below here are for the gyro
	if (m_drive->first_iteration ) {
		bool is_calibrating = m_drive->getIMU()->IsCalibrating();
		if ( !is_calibrating ) {
			Wait( 0.3 );
			m_drive->getIMU()->ZeroYaw();
			m_drive->first_iteration = false;
		}
	}
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
	oi->checkInput(); // runs through a function to check all the used buttons and joysticks

	SmartDashboard::PutBoolean("Recycler Bottom",m_recycler->isLowerSensorTripped());
	SmartDashboard::PutBoolean("Recycler Top" , m_recycler->isUpperSensorTripped());
	SmartDashboard::PutNumber("Elevator Height",m_elevator->getCurrentHeight());
	SmartDashboard::PutBoolean("Tote Sensor",m_intake->IsFrontSensorTripped());



	if(oi->GetDebugJoystickButton(16)){
		std::cout << "Voltage :"  << m_elevator->getCurrentVoltageOfSensor() << "\tHeight: " << m_elevator->getCurrentHeight() << std::endl;
	}
	else{

	}
	Wait(0.01);
}

void Robot::TestPeriodic()
{
	lw->Run();
}

void Robot::runDebug(int mode){
	switch(mode){
	case debug_driveCoefficients:{
		std::cout << "Running the drive coefficient debug mode." << std::endl;
		break;
	}
	case debug_PIDs:{
		std::cout << "Running the PID value debug mode." << std::endl;
		break;
	}
	case debug_DIOs:{
		//std::cout << "Running the DIO state debug mode." << std::endl;
		cout << m_intake->IsFrontSensorTripped();
		cout << m_intake->GetBinSensor();
		cout << m_recycler->isLowerSensorTripped();
		cout << m_recycler->isUpperSensorTripped() << "\t";
		cout << m_elevator->getCurrentVoltageOfSensor() << "\t\t";
		cout << m_elevator->convertVoltsToInches(m_elevator->getCurrentVoltageOfSensor()) << "\t";
		cout << m_drive->GetLeftDistanceTraveled() << "\t\t";
		cout << m_drive->GetRightDistanceTraveled() << "\t\t";
		cout << m_drive->GetDistanceTraveled() << "\t";
		cout << endl;
		break;
	}
	case debug_elevator:{
		std::cout << "Running the elevator debug mode." << std::endl;
		break;
	}
	case debug_driveClock:{
		std::cout << "Running the drive clock debug mode." << std::endl;
		break;
	}
	default:{
		std::cout << "Running the default debug mode. Nothing else selected" << std::endl;
		break;
	}
	}
}

START_ROBOT_CLASS(Robot);

