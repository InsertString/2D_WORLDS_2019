#include "main.h"
#include "robot_includes/robot_includes.hpp"


Lift_Systems::Lift_Systems() {
  cap_scoring_arm_state = 1;
  cap_scoring_arm_velocity = 100;
  cap_scoring_arm_target = ZERO_ARM;
}




void Lift_Systems::setFlipperPower(int power) {
  capFlipperMotor = power;
}




void Lift_Systems::setCapScorerPower(int power) {
  capScorerMotor = power;
}





void Lift_Systems::driveControl() {

  if (partner.is_connected() == true) {

  }
  else {


    if (master.get_digital_new_press(DIGITAL_A)) {
      cap_scoring_arm_target = HOLDING_CAP;
      cap_scoring_arm_velocity = 100;

    }
    else if (master.get_digital_new_press(DIGITAL_X)) {
      cap_scoring_arm_target = SCORING_CAP;
      cap_scoring_arm_velocity = 200;

    }
    else if (master.get_digital_new_press(DIGITAL_B)) {
      cap_scoring_arm_target = ZERO_ARM;
      cap_scoring_arm_state = 1;
    }


    if (cap_scoring_arm_target != ZERO_ARM) {
      capScorerMotor.move_absolute(cap_scoring_arm_target, cap_scoring_arm_velocity);
    }
    else {
      if (capScoringArmLimit.get_value() == false && cap_scoring_arm_state == 1) {
        setCapScorerPower(-127);
      }
      else {
        cap_scoring_arm_state = 0;
        capScorerMotor.tare_position();
        setCapScorerPower(0);
      }
    }

  }

}
