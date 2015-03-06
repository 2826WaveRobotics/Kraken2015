
#ifndef TOTEWAIT_H
#define WAVEWAIT_H


#include "../CommandBase.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ToteWait: public Command {
public:
	ToteWait();
	ToteWait(double seconds);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
