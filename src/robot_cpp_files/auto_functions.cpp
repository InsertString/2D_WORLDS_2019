#include "main.h"
#include "robot_includes/robot_includes.hpp"






void reset_auto_variables() {
  placeholder_1 = {INCOMPLETE, 0};
	placeholder_2 = {INCOMPLETE, 0};
	placeholder_3 = {INCOMPLETE, 0};
  chassis.resetChassisSensors(false);
  auto_drive_step = 0;
  auto_turn_step = 0;
  auto_turn_vision_step = 0;
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









Auto_Action auto_drive(int target, int max_power) {
  //create a new auto_action
  Auto_Action auto_struct;

  switch (auto_drive_step) {
    case 0 :
    //set defualt values for auto_struct
    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = 0;

    //initialise auto_drive_PID
    auto_drive_PID.set_PID_vars(0.5, 0.5, 0.5, 5);//tune these
    auto_drive_PID.target = target;
    auto_drive_PID.current = 0;

    //initialize auto_gyro_correction_PID
    auto_gyro_correction_PID.set_PID_vars(1, 0, 0, 0);//tune these
    auto_gyro_correction_PID.target = 0;
    auto_gyro_correction_PID.current = 0;

    //reset all chassis sensors
    chassis.resetChassisSensors(true);

    //reset timers
    startTimer(AUTO_DRIVE_TIMEOUT);
    startTimer(AUTO_DRIVE_EXIT);

    //advance to the next step
    auto_drive_step++;
    break;
    case 1 :

    auto_struct.return_state = INCOMPLETE;
    auto_struct.public_value = auto_drive_PID.error();

    //set PID current values
    auto_drive_PID.current = chassis.right_encoder_val();
    auto_gyro_correction_PID.current = gyro.get_value();

    //placeholder output variables
    int right_output;
    int left_output;

    //calculate output power
    right_output = auto_drive_PID.output(max_power) + auto_gyro_correction_PID.output((127 - abs(max_power)));
    left_output = auto_drive_PID.output(max_power) - auto_gyro_correction_PID.output((127 - abs(max_power)));

    //power the drive train
    chassis.setRight(right_output);
    chassis.setLeft(left_output);

    if (abs(auto_drive_PID.error()) < 5 || getTime(AUTO_DRIVE_TIMEOUT) > 3000) {
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
