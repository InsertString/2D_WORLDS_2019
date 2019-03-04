#include "main.h"
#include "robot_includes/robot_includes.hpp"


PID::PID() {
  kp = 0;
  ki = 0;
  kd = 0;

  target = 0;
  current = 0;

  data[ERROR] = 0;
  data[INTEGRAL] = 0;
  data[DERIVATIVE] = 0;
  data[PAST_ERROR] = 0;
  data[CONST_INTEGRAL] = false;
  data[INTEGRAL_LIMIT] = 0;
  data[CONST_INT_VAL] = 0;
}





void PID::set_PID_vars(float p, float i, float d, int integral_limit) {
  kp = p;
  ki = i;
  kd = d;
  data[INTEGRAL_LIMIT] = integral_limit;
}






void PID::set_PID_vars(float p, int i_val, float d, int integral_limit, bool const_int) {
  kp = p;
  kd = d;
  data[INTEGRAL_LIMIT] = integral_limit;
  data[CONST_INT_VAL] = i_val;
  data[CONST_INT_VAL] = const_int;
}







int PID::output(int max_power) {
  //create output variable
  int out;
  //set past error before error get updated
  //past error is the error from the last cycle before it gets updated
  data[PAST_ERROR] = data[ERROR];
  //set error
  //error is the difference between the target and the curent value
  data[ERROR] = target - current;
  //set derivative
  data[DERIVATIVE] = data[ERROR] - data[PAST_ERROR];

  data[INTEGRAL] = data[CONST_INTEGRAL] == true ? abs(data[INTEGRAL]) < data[INTEGRAL_LIMIT] ? (data[INTEGRAL] = data[INTEGRAL] + data[ERROR]) : (data[INTEGRAL] = 0) : (data[INTEGRAL] = data[CONST_INT_VAL]);

  out = (data[ERROR] * kp) + (data[INTEGRAL] * ki) + (data[DERIVATIVE] * kd);
  out = out > max_power ? max_power : -out < -max_power ? -max_power : out;
  return out;
}
