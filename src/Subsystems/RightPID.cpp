//Thanks to Team 254 for the PID implementation
#include "RightPID.h"
#include <stdio.h>

RightPID::RightPID(double* kP, double* kI, double* kD)
: PIDController(1.0, 0.0, 0.0, this, this)
{
  kP_ = kP;
  kI_ = kI;
  kD_ = kD;
  originalP = *kP;
  ResetError();
}

void RightPID::ResetError() {
  errorSum_ = 0;
  lastError_ = 0;
}

double RightPID::Update(double goal, double currentValue) {
  if(goal != lastGoal)
  {
	  setGain(goal);
	  ResetError();
	  lastGoal = goal;
  }
  double error = goal - currentValue;
  double p = *kP_ * error;
  errorSum_ += error;
  double i = *kI_ * errorSum_;
  double dError = error - lastError_;
  double d = *kD_ * dError;
  lastError_ = error;
  return p + i + d;
}

void RightPID::addGainSchedule(float begRange, float begGain, float endRange, float endGain)
{
	GainRange *range = new GainRange;
	range->beg = begRange;
	range->end = endRange;
	range->begGain = begGain;
	range->endGain = endGain;
	gainSchedules.push_back(*range);
}

void RightPID::setGain(double goal)
{
	for(vector<GainRange>::iterator iter = gainSchedules.begin(); iter != gainSchedules.end(); iter++)
	{
		if(goal >= iter->beg && goal <= iter->end)
		{
			*kP_ = ((iter->endGain - iter->begGain)/(iter->end - iter->beg)) * (goal - iter->beg) + iter->begGain;
			printf("Gain has been scheduled: P = %f\n", *kP_);
			return;
		}
	}
	*kP_ = originalP;
}

double RightPID::PIDGet()
{

}

void RightPID::PIDWrite(float output)
{

}

