#include "Commands/BinJugglerCommand.h"
#include "../Robot.h"

namespace
{
const double c_pinTime = 0.25;
const double c_liftTime = .75;
}
BinJugglerCommand::BinJugglerCommand(int configuration = Bin_LeftActive)
{
	Requires(Robot::m_binJuggler);
	newConfiguration = configuration;
}

void BinJugglerCommand::Initialize()
{
	Robot::m_binJuggler->UseJugglerSystem(true);
	m_waitTimer2.Reset();
	m_waitTimer2.Start();
	step = 1;

	std::cout << "BinJugglerCommand: Initialize" << std::endl;

	currentPosition = Robot::m_binJuggler->getCurrentLocation();

	if((currentPosition == Bin_CenterActive) && (newConfiguration == Bin_LoadLeft))
	{
		set = Bin_CenterToLeft;
		std::cout << "Switching from center to left:" << std::endl;
	}
	else if((currentPosition == Bin_CenterActive) && (newConfiguration == Bin_LoadRight))
	{
		set = Bin_CenterToRight;
		std::cout << "Switching from center to right:" << std::endl;
	}
	else if((currentPosition == Bin_LeftActive) && (newConfiguration == Bin_LoadCenter))
	{
		set = Bin_LeftToCenter;
		std::cout << "Switching from left to center:" << std::endl;
	}
	else if((currentPosition == Bin_LeftActive) && (newConfiguration == Bin_LoadRight))
	{
		set = Bin_LeftToRight;
		std::cout << "Switching from left to right:" << std::endl;
	}
	else if((currentPosition == Bin_RightActive) && (newConfiguration == Bin_LoadCenter))
	{
		set = Bin_RightToCenter;
		std::cout << "Switching from right to center:" << std::endl;
	}
	else if((currentPosition == Bin_RightActive) && (newConfiguration == Bin_LoadLeft))
	{
		set = Bin_RightToLeft;
		std::cout << "Switching from right to left:" << std::endl;
	}
	else
	{
		set = Bin_SameToSame;
		std::cout << "No switching- already at destination!" << std::endl;
	}
	step = 1;
	m_sequenceFinished = false;


}

void BinJugglerCommand::Execute()
{
	switch(set)
	{
	case Bin_CenterToRight://////////////////////////////////////////////Center___To_____Right/////////////////////////////
	{
		/**Steps:
		 * Lock left
		 * Open right
		 * ->Wait(Pin)
		 * Close lift cylinder
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, Off);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "1. Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			std::cout << "2. Check timer" << std::endl;
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}

		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder,Off);
			//wait (maybe?)
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "3. Setting timer to " << c_liftTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			std::cout << "4. Check timer" << std::endl;
			//check if time has passed, if yes then step = 7;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			currentPosition = Bin_RightActive;
			std::cout << "5. Setting actual movement from center to right" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}

	case Bin_CenterToLeft://////////////////////////////////////Center___To____Left///////////////////////////////////////////
	{
		/**Steps:
		 * Lock right
		 * Open left
		 * ->Wait(Pin)
		 * Close lift cylinder
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, Off);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "1. Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			std::cout << "2. Check timer" << std::endl;
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}

		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder,Off);
			//wait (maybe?)
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "3. Setting timer to " << c_liftTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			std::cout << "4. Check timer" << std::endl;
			//check if time has passed, if yes then step = 7;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			currentPosition = Bin_LeftActive;
			std::cout << "5. Setting actual movement from center to left" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}
	case Bin_LeftToCenter://///////////////////////////////////////Left_____To______Center/////////////////////////
	{
		/**Steps
		 * Unlock Left
		 * Lock Right
		 * Wait (pins)
		 * Open Lift Cylinder
		 * Wait (lift)
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, Off);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}
		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			//Close both the left lock and the right lock
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
			currentPosition = Bin_CenterActive;
			std::cout << "Setting actual movement from left to center" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}

	case Bin_LeftToRight://////////////////////////////////Left_____To_____Right///////////////////////////////////////////////
	{
		/**Steps
		 * Open Lift Cylinder
		 * ->Wait (lift)
		 * Lock Left
		 * Unlock Right
		 * ->Wait (pin)
		 * Close Lift Cylinder
		 * ->Wait (lift)
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}
		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, Off);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_pinTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			//check if time has passed, if yes then step = 5;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder,Off);
			//wait (maybe?)
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 6;
		}
		else if(6 == step)
		{
			//check if time has passed, if yes then step = 7;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 7;
				m_waitTimer.Stop();
			}
		}
		else if(7 == step)
		{
			currentPosition = Bin_RightActive;
			std::cout << "Setting actual movement from left to right" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}

	case Bin_RightToCenter:///////////////////////////////////////////Right____To______Center/////////////////////////////
	{
		/**Steps
		 * Lock Left
		 * Unlock Right
		 * Wait (pins)
		 * Open Lift Cylinder
		 * Wait (lift)
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, Off);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}
		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			//Close both the left lock and the right lock
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, On);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
			currentPosition = Bin_CenterActive;
			std::cout << "Setting actual movement from right to center" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}

	case Bin_RightToLeft:///////////////////////// RIGHT   TO    LEFT   ///////////////////////////
	{
		/**Steps
		 * Open Lift Cylinder
		 * ->Wait (lift)
		 * Lock Right
		 * Unlock Left
		 * ->Wait (pin)
		 * Close Lift Cylinder
		 * ->Wait (lift)
		 */
		if(1 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 2;
		}
		else if(2 == step)
		{
			//check if time has passed, if yes then step = 3;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 3;
				m_waitTimer.Stop();
			}
		}
		else if(3 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LeftLock, Off);
			Robot::m_binJuggler->loadSelection(Bin_RightLock, On);
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_pinTime << std::endl;
			step = 4;
		}
		else if(4 == step)
		{
			//check if time has passed, if yes then step = 5;
			if(m_waitTimer.HasPeriodPassed(c_pinTime))
			{
				step = 5;
				m_waitTimer.Stop();
			}
		}
		else if(5 == step)
		{
			Robot::m_binJuggler->loadSelection(Bin_LiftCylinder,Off);
			//wait (maybe?)
			m_waitTimer.Reset();
			m_waitTimer.Start();
			std::cout << "Setting timer to " << c_liftTime << std::endl;
			step = 6;
		}
		else if(6 == step)
		{
			//check if time has passed, if yes then step = 7;
			if(m_waitTimer.HasPeriodPassed(c_liftTime))
			{
				step = 7;
				m_waitTimer.Stop();
			}
		}
		else if(7 == step)
		{
			currentPosition = Bin_LeftActive;
			std::cout << "Setting actual movement from right to left" << std::endl;
			m_sequenceFinished = true;
		}
		break;
	}

	case Bin_SameToSame:
		//already there!
		std::cout << "Already there!" << std::endl;
		m_sequenceFinished = true;
		break;
	default:
		//Do nothing
		break;
	}

	Robot::m_binJuggler->setCurrentLocation(currentPosition);

}

bool BinJugglerCommand::IsFinished()
{
	if(m_sequenceFinished){
		std::cout << "Sequence is Finished " << m_sequenceFinished << std::endl;
		return true;
	}
	else{
		return m_sequenceFinished;
	}
}

void BinJugglerCommand::End()
{
	std::cout << "Ending Bin Juggler Command" << std::endl;
	std::cout << "Bin Juggler Command took " << m_waitTimer2.Get() << " seconds" << std::endl;

	Robot::m_binJuggler->UseJugglerSystem(false);
}

void BinJugglerCommand::Interrupted()
{
	std::cout << "Bin Juggler Interrupted" << std::endl;
	Robot::m_binJuggler->UseJugglerSystem(false);
}
