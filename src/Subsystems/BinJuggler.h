#ifndef Bin_Juggler_H
#define Bin_Juggler_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinJuggler: public Subsystem
{
private:
	 Solenoid* m_jugglerLift;
		 Solenoid* m_leftLock;
		 Solenoid* m_rightLock;
		 Solenoid* m_leftGrab;
		 Solenoid* m_rightGrab;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
		 int active;
public:
	BinJuggler();
	void InitDefaultCommand();
	void loadSelection(int cylinder, bool state);
	void setActive(int currentActive);
	int returnActive();


};

#endif
