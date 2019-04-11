#ifndef _PID_HPP_
#define _PID_HPP_


#define ERROR 0
#define INTEGRAL 1
#define DERIVATIVE 2
#define PAST_ERROR 3
#define CONST_INTEGRAL 4
#define INTEGRAL_LIMIT 5
#define CONST_INT_VAL 6


class PID {
public:
  PID();
  int output(int max_power);
  int current;
  int target;
  float error();
  void set_PID_vars(float p, float i, float d, int integral_limit);
  void set_PID_vars(float p, int i_val, float d, int integral_limit, bool const_int);
  void post(int post);
private:
  float kp;
  float ki;
  float kd;
  float data[7];
};

#endif
