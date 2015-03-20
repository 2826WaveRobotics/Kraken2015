#include "Commands/BinJugglerCommand.h"
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "OI.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Recycler.h"
#include "Subsystems/Intake.h"
#include "Subsystems/BinJuggler.h"
#include "Subsystems/CompressorSubsystem.h"
#include "Subsystems/Drive.h"
#include "Subsystems/ExampleSubsystem.h"
#include "IMU.h"
#include "IMUAdvanced.h"
#include "AHRS.h"

class Robot: public IterativeRobot
{

public:
	static Drive* m_drive;
	static Elevator* m_elevator;
	static Recycler* m_recycler;
	static Intake* m_intake;
	static BinJuggler* m_binJuggler;
	static CompressorSubsystem* m_compressor;
	static OI *oi;

	void runDebug(int debugMode);
	double GetYaw();
	void ZeroGyro();

private:
	Command *autonomousCommand;
	Command *binCommand; // for bin test
	LiveWindow *lw;

	SendableChooser *autoChooser;

	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();

	//	PowerDistributionPanel PDBoard;

};
