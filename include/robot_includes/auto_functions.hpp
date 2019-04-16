#ifndef _AUTO_FUNCTIONS_HPP_
#define _AUTO_FUNCTIONS_HPP_


enum Auto_Action_Return_States {
  COMPLETE,
  INCOMPLETE,
};


#define AUTO_PIVOT_LEFT 1
#define AUTO_PIVOT_RIGHT 2






struct Auto_Action {
  Auto_Action_Return_States return_state;
  int public_value;
};





Auto_Action auto_drive(int target, int max_power, int timeout);


Auto_Action auto_turn(int target, int max_power, int timeout);


Auto_Action auto_turn_swing(int target, int pivot, int max_power, int timeout);


Auto_Action auto_shoot(int timeout);


Auto_Action auto_move_arm(int target, int velocity, int timeout);


Auto_Action auto_move_flipper(int target, int velocity, int timeout);





void start_auto();
void reset_auto_variables();
void advance_auto_step();



#endif
