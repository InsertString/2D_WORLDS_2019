#include "main.h"
#include "robot_includes/robot_includes.hpp"


Lift_Systems::Lift_Systems() {
  cap_scoring_arm_state = 1;
  cap_scoring_arm_velocity = 100;
  cap_scoring_arm_target = ZERO_ARM;
  arm_position = 0;
  flipper_power = 0;
}




void Lift_Systems::setFlipperPower(int power) {
  capFlipperMotor = power;
}




void Lift_Systems::setCapScorerPower(int power) {
  capScorerMotor = power;
}



int ww;

void Lift_Systems::driveControl() {

  if (abs(partner.get_analog(ANALOG_LEFT_Y)) > 20) {

    if (partner.get_analog(ANALOG_LEFT_Y) > 0 && capScoringArmLimit.get_value() == true) {
      capScorerMotor = 0;
    }
    else {
      capScorerMotor = -partner.get_analog(ANALOG_LEFT_Y);
    }

    arm_position = capScorerMotor.get_position();
  }
  else {
    capScorerMotor.move_absolute(arm_position, 20);
  }



  if (partner.get_analog(ANALOG_RIGHT_Y) > 20) {
    if (capFlipperLimit.get_value() == false) {
      flipper_power = partner.get_analog(ANALOG_RIGHT_Y);

      if (fabs(capFlipperMotor.get_position()) < 150) {
        flipper_power = flipper_power > 40 ? 40 : flipper_power;
      }
      

      capFlipperMotor = flipper_power;
      flipper_position = capFlipperMotor.get_position();
      ww = 0;
    }
    else if (capFlipperLimit.get_value() == true) {
      if (ww == 0) {
        capFlipperMotor.tare_position();
        ww = 1;
      }
      capFlipperMotor.move_absolute(0, 200);
    }
  }
  else if (partner.get_analog(ANALOG_RIGHT_Y) < -20) {
    flipper_power = partner.get_analog(ANALOG_RIGHT_Y);
    flipper_power = flipper_power < -60 ? -60 : flipper_power;
    capFlipperMotor = flipper_power;
    flipper_position = capFlipperMotor.get_position();
  }
  else {
    if (capFlipperLimit.get_value() == true) {
      if (ww == 0) {
        capFlipperMotor.tare_position();
        ww = 1;
      }
      capFlipperMotor.move_absolute(0, 200);
    }
    else {
      capFlipperMotor.move_absolute(flipper_position, 20);
    }
  }

}
