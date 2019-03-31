#ifndef _AUTO_FUNCTIONS_HPP_
#define _AUTO_FUNCTIONS_HPP_


enum Auto_Function {
  COMPLETE,
  INCOMPLETE,
  FLAGGED
};


#define AUTO_TURN_LEFT 1
#define AUTO_TURN_RIGHT 2



Auto_Function auto_drive(int target, int max_power, bool flag, int flag_range, int flag_mid);
Auto_Function auto_drive(int target, int max_power);


Auto_Function auto_turn(int target, int max_power, bool flag, int flag_range, int flag_mid);
Auto_Function auto_turn(int target, int max_power);


Auto_Function auto_turn_vision(int direction, int gyro_target, int vision_target, bool flag, int flag_range, int flag_mid);
Auto_Function auto_turn_vision(int direction, int gyro_target, int vision_target);


Auto_Function auto_shoot();


Auto_Function auto_move_arm(int target, int velocity, bool flag, int flag_range, int flag_mid);
Auto_Function auto_move_arm(int target, int velocity);


Auto_Function auto_move_flipper(int target, int velocity, bool flag, int flag_range, int flag_mid);
Auto_Function auto_move_flipper(int target, int velocity);


#endif
