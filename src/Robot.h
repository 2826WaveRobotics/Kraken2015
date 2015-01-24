#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Elevator.h"
#include "Subsystems/Recycler.h"

class Robot: public IterativeRobot
{
public:
	static Drive* m_drive;
	static Elevator* m_elevator;
	static Recycler* m_recycler;

private:
	Command *autonomousCommand;
	LiveWindow *lw;
	static OI *oi;

	void RobotInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();

};
