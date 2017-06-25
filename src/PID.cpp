#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte-p_error;
    i_error += cte;
    p_error = cte;   
}

double PID::TotalError(double running_counter) {
    return p_error/running_counter;
}

double PID::GetSteer() {
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}