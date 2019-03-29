#include "main.h"
#include "robot_includes/robot_includes.hpp"




Vision_Control::Vision_Control() {
  target_colour = VISION_RED;
  on_target = 0;
}







void Vision_Control::driveControl() {


  //displays target colour on the vision LED
  if (target_colour == VISION_RED) {
    vision.set_led(COLOR_RED);
  }
  else if (target_colour == VISION_BLUE) {
    vision.set_led(COLOR_BLUE);
  }
  else if (target_colour == VISION_GREEN) {
    vision.set_led(COLOR_GREEN);
  }



  //target colour swapper
  if (master.get_digital_new_press(DIGITAL_Y)) {
    target_colour = target_colour == VISION_GREEN ? VISION_BLUE : target_colour == VISION_RED ? VISION_GREEN : target_colour == VISION_BLUE ? VISION_RED : target_colour;
  }



  if (master.get_digital(DIGITAL_R2)) {
    int power_left;
    int power_right;

    //request priority for control over the drive
    chassis.requestDrivePriority(DRIVE_PRIORITY_VISION);


    pros::vision_object_s_t flag = vision.get_by_sig(0, target_colour);

    vision_PID.set_PID_vars(0.6, 0.1, 1, 10);
    vision_PID.target = 0;
    vision_PID.current = flag.x_middle_coord;

    chassis.request_left(-vision_PID.output(50));
    chassis.request_right(vision_PID.output(50));


    //rumble the controller when lined up
    if (abs(flag.x_middle_coord) < 10) {
      //only rumble once
      if (on_target == 0) {
        master.rumble("- - -");
      }
      on_target = 1;
    }
    else {
      on_target = 0;
    }
  }
  else {
    if (chassis.drive_system_priority == DRIVE_PRIORITY_VISION) {
      chassis.request_left(0);
      chassis.request_right(0);
    }
  }
}
