/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kpi = Kp;
  Kdi = Kd;
  Kii = Ki;
  
  _output_lim_max = output_lim_max;
  _output_lim_min = output_lim_min;
  
  p_error = 0.0;
  d_error = 0.0;
  i_error = 0.0;
  
  delta_time = 0.0;
   
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if (delta_time > 0) {
    d_error = (cte - p_error) / delta_time;
  }else{
    d_error = 0.0;
  }
  
  p_error = cte;
  i_error += cte * delta_time;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
  	control = Kpi * p_error + Kdi * d_error + Kii * i_error;
  	if (control > _output_lim_max){
      control = _output_lim_max;
    }
  	else if (control < _output_lim_min){
      control = _output_lim_min;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  delta_time = new_delta_time;
  
  return delta_time;
}