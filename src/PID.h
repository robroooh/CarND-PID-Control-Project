#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;
  
  /*For Twiddling*/
  double cum_error;
  int adjusting_variable;
  double best_error;
  double dp_p;
  double dp_i;
  double dp_d;
  bool tweak;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd, double dp_p, double dp_i, double dp_d);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError(double running_counter);

  double GetSteer();

  void ClearCumErrorRunningCt();
  void Twiddle(double running_counter);
};

#endif /* PID_H */
