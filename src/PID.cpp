#include "PID.h"
#include <math.h>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double dp_p, double dp_i, double dp_k) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->p_error = 0.0;
  this->i_error = 0.0;
  this->d_error = 0.0;
  this->cum_error = 0.0;
  this->adjusting_variable = 0;
  this->best_error = 10000000.0;
  this->dp_p = dp_p;
  this->dp_i = dp_i;
  this->dp_d = dp_d;
}

void PID::UpdateError(double cte) {
    d_error = cte-p_error;
    i_error += cte;
    p_error = cte;
    cum_error += fabs(cte);
}

void PID::ClearCumErrorRunningCt(){
    cum_error = 0.0;
}

double PID::TotalError(double running_counter) {
    return cum_error/running_counter;
}

double PID::GetSteer() {
    double steer_value = -Kp * p_error - Kd * d_error - Ki * i_error;
    steer_value = steer_value < -1.0? -1.0 : steer_value;
    steer_value = steer_value > 1.0? 1.0 : steer_value;
    return steer_value;
}

void PID::Twiddle(double running_counter){
    double err = TotalError(running_counter);
    
    if (!tweak){
        if (err < best_error){
            best_error = err;
            if (adjusting_variable == 0) {
                dp_p *= 1.1;
            } else if (adjusting_variable == 1) {
                dp_i *= 1.1;
            } else {
                dp_d *= 1.1;
            }
        } else {
            if (adjusting_variable == 0) {
                Kp -= 2*dp_p;
            } else if (adjusting_variable == 1) {
                Ki -= 2*dp_i;
            } else {
                Kd -= 2*dp_d;
            }
            tweak = true;
            return;
        }
    } else {
        if (err < best_error) {
            best_error = err;
        } else {
            if (adjusting_variable == 0) {
                Kp += dp_p;
                dp_p *= 0.9;
            } else if (adjusting_variable == 1) {
                Ki += dp_i;
                dp_i *= 0.9;
            } else {
                Kd += dp_d;
                dp_d *= 0.9;
            } 
        }
        tweak=false;
        adjusting_variable = (adjusting_variable+1)%3;
    }
    
}