#ifndef RIGHT_PID_H
#define RIGHT_PID_H

/**
 * @author Bhargava Manja
 * @author Francisco Sanchez
 *
 * Pid class for generic error correction: scales error to create next motor input and achieve desired value
 */
#include <vector>
#include "WPILib.h"

using namespace std;



class RightPID : public PIDController, public PIDSource, public PIDOutput {
 public:
  /**
   * Constructor
   * Accepts the kP, kI, and kD to determine the correction value
   * Defaults to (0,0,0) - useful when a class has member Pid's
   */
   RightPID(double* kP = 0, double* kI = 0, double* kD = 0);
  /**
   * Resets the error counts. Call when the PID loop is not active to prevent integral windup.
   */
  void ResetError();

  /**
   * Returns the output of the PID controller for the current state of the system.
   * @param goal The current goal to reach
   * @param currentValue The current value of the quantity to be corrected
   */
  double Update(double goal, double currentValue);

  /**
   * Sets the values for gain scheduling
   * @param begRange - The beginning of the range
   * @param startGain - The gain for the beginning
   * @param endRange - The end of the range
   * @param endGain - the gain for the end
   * This allows for the ability to add segments of linear gain scheduling.
   * The first valid range found is the gain that will be scheduled.
   * If no valid ranges are found the P gain will default to the
   * constructed value
   */
  void addGainSchedule(float begRange, float begGain, float endRange, float endGain);

  virtual double PIDGet();
  virtual void PIDWrite(float output);

 private:
  void setGain(double goal);
  struct GainRange
  {
  	float beg;
  	float end;
  	float begGain;
  	float endGain;
  };
  // PID constants
  double  originalP;
  double* kP_;
  double* kI_;
  double* kD_;

  vector<GainRange> gainSchedules;

  //last goal value, so we don't continually calculate the gain schedule
  double lastGoal;

  // Cumulative error used in integral term
  double errorSum_;

  // Last error value used to find error difference for derivative term
  double lastError_;
};

#endif  // SUBSYSTEMS_PID_H_
