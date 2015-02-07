#include "BinJuggler.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

BinJuggler::BinJuggler() :
		Subsystem("BinJuggler")
{
	m_jugglerLift= RobotMap::jugglerLift;
 m_leftLock= RobotMap ::leftLock;
 m_rightLock= RobotMap::rightLock;
 m_leftGrab= RobotMap::leftGrab;
 m_rightGrab= RobotMap::rightGrab;

}

void BinJuggler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void BinJuggler::loadSelection(int cylinder, bool state) {

	switch(cylinder) {
	case Bin_LiftCylinder:
		m_jugglerLift-> Set(state);
		break;
	case Bin_LeftLock:
		m_leftLock-> Set(state);
		break;
	case Bin_RightLock:
		m_rightLock-> Set(state);
		break;
	default:
		break;
	}
	//	switch(configuration)
//	{
//		case Bin_CenterConfig:
//			m_jugglerLift-> Set(On);
//			m_leftLock->Set(On);
//			m_rightLock->Set(On);
//			break;
//		case Bin_LeftConfig:
//			m_jugglerLift-> Set(Off);
//			m_leftLock->Set(Off);
//			m_rightLock->Set(On);
//			break;
//		case Bin_RightConfig:
//			m_jugglerLift-> Set(Off);
//			m_leftLock->Set(On);
//			m_rightLock->Set(Off);
//			break;
//		default:
//			//Do nothing
//			break;
//	}



}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void BinJuggler::setActive(int currentActive)
{
	active = currentActive;
}

int BinJuggler::returnActive()
{
	return active;
}


