#include "Subsystems/PIDDrive.h"
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
#include "Subsystems/Swim.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Drive.h"

class Robot: public IterativeRobot
{
public:
	static Drive* m_drive;
	static Elevator* m_elevator;
	static Recycler* m_recycler;
	static Intake* m_intake;
	static BinJuggler* m_binJuggler;
	static CompressorSubsystem* m_compressor;
	static Swim* m_swim;
	static OI *oi;

private:
	Command *autonomousCommand;

	Command *binCommand; // for bin test
	LiveWindow *lw;

	void RobotInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();

//	PowerDistributionPanel PDBoard;

};
