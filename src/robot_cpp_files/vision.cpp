#include "main.h"
#include "robot_includes/robot_includes.hpp"




Vision_Control::Vision_Control() {
  target_colour = VISION_RED;
}







void Vision_Control::driveControl() {



  if (master.get_digital(DIGITAL_R2)) {
    int power_left;
    int power_right;

    //request priority for control over the drive
    chassis.requestDrivePriority(DRIVE_PRIORITY_VISION);


    pros::vision_object_s_t flag = vision.get_by_sig(0, target_colour);
/*
    int error;
    error = 30 - flag.x_middle_coord;

    power_left = -error*0.5;
    power_right = error*0.5;
*/

    vision_PID.set_PID_vars(0.6, 0.1, 1, 10);
    vision_PID.target = 0;
    vision_PID.current = flag.x_middle_coord;

    power_left = -vision_PID.output(50);
    power_right = vision_PID.output(50);

    chassis.request_left(power_left);
    chassis.request_right(power_right);
  }
}
