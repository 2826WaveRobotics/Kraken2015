#ifndef Bin_Juggler_H
#define Bin_Juggler_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinJuggler: public Subsystem
{
private:
		 Solenoid* m_jugglerLift; // center cylinder
		 Solenoid* m_leftLock;
		 Solenoid* m_rightLock;
		 Solenoid* m_leftHook;
		 Solenoid* m_rightHook;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

		 int active;
		 int m_cycle;// = 1;
		 int m_currentLocation;
public:
	BinJuggler();
	void InitDefaultCommand();
	void loadSelection(int cylinder, bool state);
	void sequenceUp(bool trueForUp);

	void hookLeft(bool extend);
	void hookRight(bool extend);
	void expand();
	void contract();
	void lockLeft(bool extend);
	void lockRight(bool extend);

	int getCurrentLocation();
	void setCurrentLocation(int newLocation);


};

#endif
