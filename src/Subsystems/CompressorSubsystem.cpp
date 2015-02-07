#include "CompressorSubsystem.h"
#include "../RobotMap.h"
#include "../WaveConstants.h"

CompressorSubsystem::CompressorSubsystem() :
		Subsystem("CompressorSubsystem")
{
 compressor = RobotMap::compressor;

}

void CompressorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void CompressorSubsystem::Start()
{
compressor->Start();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void CompressorSubsystem::Stop()
{
compressor->Stop();

}

