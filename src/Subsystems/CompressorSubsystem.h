#ifndef COMPRESSOR_SUBSYSTEM_H
#define COMPRESSOR_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class CompressorSubsystem: public Subsystem
{
private:
		 Compressor* compressor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	CompressorSubsystem();
	void InitDefaultCommand();
	void Start();
	void Stop();
};

#endif
