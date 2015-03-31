#include "BinJuggler.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

BinJuggler::BinJuggler() :
Subsystem("BinJuggler")
{
	m_jugglerLift= RobotMap::jugglerCylinder;
	m_leftLock= RobotMap ::leftLock;
	m_rightLock= RobotMap::rightLock;
	m_leftHook= RobotMap::leftHook;
	m_rightHook= RobotMap::rightHook;
	m_currentLocation= Bin_LeftActive;
	m_jugglerSystemInUse = false;

}
bool BinJuggler::IsJugglerSystemInUse()
{
	return m_jugglerSystemInUse;
}

void BinJuggler::UseJugglerSystem(bool inUse)
{
	m_jugglerSystemInUse=inUse;
}
void BinJuggler::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void BinJuggler::BinJugglerTest(){
	std::cout << "Testing Bin Juggler" << std::endl;
}

void BinJuggler::loadSelection(int cylinder, bool state) {

	switch(cylinder) {
	case Bin_LiftCylinder:
		m_jugglerLift-> Set(state);
		//std::cout << "Setting Lift Cylinder to " << state << std::endl;
		break;
	case Bin_LeftLock:
		m_leftLock-> Set(!state);
		//std::cout << "Setting Left Lock to " << state << std::endl;
		break;
	case Bin_RightLock:
		m_rightLock-> Set(!state);
		//std::cout << "Setting Right Lock to " << state << std::endl;
		break;
	case Bin_RightHook:
		m_rightHook->Set(state);
		//std::cout << "Setting Right Hook to " << state << std::endl;
		break;
	case Bin_LeftHook:
		m_leftHook->Set(state);
		//std::cout << "Setting Left Hook to " << state << std::endl;
		break;
	default:
		break;
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void BinJuggler::hookLeft(bool extend = true){
	m_leftHook->Set(extend);
}
void BinJuggler::hookRight(bool extend = true){
	m_rightHook->Set(extend);
}
void BinJuggler::expand(){
	m_jugglerLift->Set(true);
}
void BinJuggler::contract(){
	m_jugglerLift->Set(false);
}
void BinJuggler::lockLeft(bool extend = true){
	m_leftLock->Set(extend);
}
void BinJuggler::lockRight(bool extend = true){
	m_rightLock->Set(extend);
}

int BinJuggler::getCurrentLocation()
{
	return m_currentLocation;
}

void BinJuggler::setCurrentLocation(int newLocation)
{
	m_currentLocation=newLocation;
}


