#ifndef _AUTO_FUNCTIONS_HPP_
#define _AUTO_FUNCTIONS_HPP_


enum Auto_Action_Return_States {
  COMPLETE,
  INCOMPLETE,
};


#define AUTO_TURN_LEFT 1
#define AUTO_TURN_RIGHT 2






struct Auto_Action {
  Auto_Action_Return_States return_state;
  int public_value;
};




Auto_Action placeholder_1;
Auto_Action placeholder_2;
Auto_Action placeholder_3;


Auto_Action auto_drive(int target, int max_power);


Auto_Action auto_turn(int target, int max_power);


Auto_Action auto_turn_vision(int direction, int gyro_target, int vision_target);


Auto_Action auto_shoot();


Auto_Action auto_move_arm(int target, int velocity);


Auto_Action auto_move_flipper(int target, int velocity);


int auto_step;


void start_auto();
void reset_auto_variables();
void advance_auto_step();


#endif
