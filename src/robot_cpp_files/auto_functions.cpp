#include "main.h"
#include "robot_includes/robot_includes.hpp"


Auto_Action action_1;
Auto_Action action_2;
Auto_Action action_3;

int auto_drive_step;
int auto_drive_accel_step;
int auto_turn_step;
int auto_turn_swing_step;
int auto_shoot_step;
int auto_move_arm_step;
int auto_move_flipper_step;
int auto_step;

void reset_auto_variables() {
  action_1 = {INCOMPLETE, 0};
	action_2 = {INCOMPLETE, 0};
	action_3 = {INCOMPLETE, 0};
  chassis.resetChassisSensors(false);
  auto_drive_step = 0;
  auto_turn_step = 0;
  auto_turn_swing_step = 0;
  auto_shoot_step = 0;
  auto_move_arm_step = 0;
  auto_move_flipper_step = 0;
  startTimer(AUTO_STEP_TIMER);
}



void advance_auto_step() {
  auto_step++;
  reset_auto_variables();
}



void start_auto() {
  reset_auto_variables();
  auto_step = 0;
  startTimer(AUTO_TIMER);
}




























/*

  ||        
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||
  ||

*/


Auto_Action auto_drive(int target, int max_power) {
  //create a new auto_action
  Auto_Action auto_struct;

  switch (auto_drive_step) {
    case 0 :
    //set defualt values for auto_struct
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;

    //initialise auto_drive_PID
    auto_drive_PID.set_PID_vars(0.7, 0.1, 5, 20);//tune these
    auto_drive_PID.target = target;
    auto_drive_PID.current = 0;

    //initialize auto_gyro_correction_PID
    auto_gyro_correction_PID.set_PID_vars(0.7, 0.1, 0, 5);//tune these
    auto_gyro_correction_PID.target = 0;
    auto_gyro_correction_PID.current = 0;

    //reset all chassis sensors
    chassis.resetChassisSensors(true);

    //reset timers
    startTimer(AUTO_DRIVE_TIMEOUT);
    startTimer(AUTO_DRIVE_EXIT);

    //advance to the next step
    auto_drive_step++;
    auto_drive_accel_step = 0;
    break;
    case 1 :

    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = auto_drive_PID.error();

    //set PID current values
    auto_drive_PID.current = frontRightDriveMotor.get_position();
    auto_gyro_correction_PID.current = gyro.get_value();

    //action output variables
    int right_output;
    int left_output;

    //calculate output power
    right_output = auto_drive_PID.output(max_power) - auto_gyro_correction_PID.output((127 - abs(max_power)));
    left_output = auto_drive_PID.output(max_power) + auto_gyro_correction_PID.output((127 - abs(max_power)));

    switch (auto_drive_accel_step) {
      case 0 :
      chassis.setRight(-right_output * 0.2);
      chassis.setLeft(-left_output * 0.2);
      auto_drive_accel_step++;
      break;
      case 1 :
      chassis.setRight(-right_output * 0.4);
      chassis.setLeft(-left_output *0.4);
      auto_drive_accel_step++;
      break;
      case 2 :
      chassis.setRight(-right_output * 0.6);
      chassis.setLeft(-left_output * 0.6);
      auto_drive_accel_step++;
      break;
      case 3:
      chassis.setRight(-right_output * 0.8);
      chassis.setLeft(-left_output * 0.8);
      auto_drive_accel_step++;
      break;
      case 4 :
      chassis.setRight(-right_output);
      chassis.setLeft(-left_output);
      break;
    }


    if (fabs(auto_drive_PID.error()) < 5 || getTime(AUTO_DRIVE_TIMEOUT) > 3000) {
      auto_drive_step = getTime(AUTO_DRIVE_EXIT) > 100 ? auto_drive_step + 1 : auto_drive_step;
    }
    else {
      startTimer(AUTO_DRIVE_EXIT);
    }

    break;
    case 2 :
    chassis.setLeft(0);
    chassis.setRight(0);
    auto_struct.return_state = COMPLETE;
    break;
  }

  return auto_struct;
}
























/*

  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||
  ||        ||

*/
Auto_Action auto_turn(int target, int max_power) {
  Auto_Action auto_struct;

  switch (auto_turn_step) {
    case 0 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;

    auto_turn_PID.set_PID_vars(0.3, 1, 1, 25);
    auto_turn_PID.target = target;
    auto_turn_PID.current = 0;

    chassis.resetChassisSensors(true);

    startTimer(AUTO_TURN_TIMEOUT);
    startTimer(AUTO_TURN_EXIT);

    auto_drive_accel_step = 0;
    auto_turn_step++;
    break;
    case 1 :

    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = auto_turn_PID.error();

    auto_turn_PID.current = gyro.get_value();

    int right_output;
    int left_output;

    right_output = auto_turn_PID.output(max_power);
    left_output = -auto_turn_PID.output(max_power);

    switch (auto_drive_accel_step) {
      case 0 :
      chassis.setRight(-right_output * 0.2);
      chassis.setLeft(-left_output * 0.2);
      auto_drive_accel_step++;
      break;
      case 1 :
      chassis.setRight(-right_output * 0.4);
      chassis.setLeft(-left_output *0.4);
      auto_drive_accel_step++;
      break;
      case 2 :
      chassis.setRight(-right_output * 0.6);
      chassis.setLeft(-left_output * 0.6);
      auto_drive_accel_step++;
      break;
      case 3:
      chassis.setRight(-right_output * 0.8);
      chassis.setLeft(-left_output * 0.8);
      auto_drive_accel_step++;
      break;
      case 4 :
      chassis.setRight(-right_output);
      chassis.setLeft(-left_output);
      break;
    }

    if (fabs(auto_turn_PID.error()) < 15 || getTime(AUTO_TURN_TIMEOUT) > 30000) {
      auto_turn_step = getTime(AUTO_TURN_EXIT) > 100 ? auto_turn_step + 1 : auto_turn_step;
    }
    else {
      startTimer(AUTO_TURN_EXIT);
    }

    break;
    case 2 :
    chassis.setLeft(0);
    chassis.setRight(0);
    auto_struct.return_state = COMPLETE;
    auto_struct.public_value = 0;
    break;
  }

  return auto_struct;
}






























Auto_Action auto_turn_swing(int target, int pivot, int max_power) {
  Auto_Action auto_struct;

  switch (auto_turn_swing_step) {
    case 0 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;

    auto_turn_swing_PID.set_PID_vars(0.3, 1, 1, 25);
    auto_turn_swing_PID.target = target;
    auto_turn_swing_PID.current = 0;

    chassis.resetChassisSensors(true);

    startTimer(AUTO_TURN_SWING_TIMEOUT);
    startTimer(AUTO_TURN_SWING_EXIT);

    auto_drive_accel_step = 0;
    auto_turn_swing_step++;
    break;
    case 1 :

    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = auto_turn_swing_PID.error();

    auto_turn_swing_PID.current = gyro.get_value();

    int right_output;
    int left_output;

    if (pivot == AUTO_PIVOT_LEFT) {
      right_output = auto_turn_swing_PID.output(max_power);
      left_output = -auto_turn_swing_PID.output(20);
    }
    else if (pivot == AUTO_PIVOT_RIGHT) {
      right_output = auto_turn_swing_PID.output(20);
      left_output = -auto_turn_swing_PID.output(max_power);
    }

    switch (auto_drive_accel_step) {
      case 0 :
      chassis.setRight(-right_output * 0.2);
      chassis.setLeft(-left_output * 0.2);
      auto_drive_accel_step++;
      break;
      case 1 :
      chassis.setRight(-right_output * 0.4);
      chassis.setLeft(-left_output *0.4);
      auto_drive_accel_step++;
      break;
      case 2 :
      chassis.setRight(-right_output * 0.6);
      chassis.setLeft(-left_output * 0.6);
      auto_drive_accel_step++;
      break;
      case 3:
      chassis.setRight(-right_output * 0.8);
      chassis.setLeft(-left_output * 0.8);
      auto_drive_accel_step++;
      break;
      case 4 :
      chassis.setRight(-right_output);
      chassis.setLeft(-left_output);
      break;
    }

    if (fabs(auto_turn_swing_PID.error()) < 15 || getTime(AUTO_TURN_SWING_TIMEOUT) > 30000) {
      auto_turn_swing_step = getTime(AUTO_TURN_SWING_EXIT) > 100 ? auto_turn_swing_step + 1 : auto_turn_swing_step;
    }
    else {
      startTimer(AUTO_TURN_SWING_EXIT);
    }

    break;
    case 2 :
    chassis.setLeft(0);
    chassis.setRight(0);
    auto_struct.return_state = COMPLETE;
    auto_struct.public_value = 0;
    break;
  }

  return auto_struct;
}






































Auto_Action auto_move_arm(int target, int velocity) {
  Auto_Action auto_struct;

  switch (auto_move_arm_step) {
    case 0 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;
    startTimer(AUTO_MOVE_ARM_TIMEOUT);
    auto_move_arm_step++;
    break;
    case 1 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = capScorerMotor.get_position();

    capScorerMotor.move_absolute(target, velocity);

    if (capScorerMotor.get_position() > (target - 5) && capScorerMotor.get_position() < (target + 5)) {
      auto_move_arm_step++;
    }
    break;
    case 2 :
    auto_struct.return_state = COMPLETE;
    auto_struct.public_value = capScorerMotor.get_position();
    break;
  }

  return auto_struct;
}

































Auto_Action auto_move_flipper(int target, int velocity) {
  Auto_Action auto_struct;

  switch (auto_move_flipper_step) {
    case 0 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;
    startTimer(AUTO_MOVE_FLIPPER_TIMEOUT);
    auto_move_arm_step++;
    break;
    case 1 :
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = capFlipperMotor.get_position();

    capFlipperMotor.move_absolute(target, velocity);

    if (capFlipperMotor.get_position() > (target - 5) && capFlipperMotor.get_position() < (target + 5)) {
      auto_move_flipper_step++;
    }
    break;
    case 2 :
    auto_struct.return_state = COMPLETE;
    auto_struct.public_value = capFlipperMotor.get_position();
    break;
  }

  return auto_struct;
}