#include "main.h"
#include "robot_includes/robot_includes.hpp"



Lift_Systems::Lift_Systems() {
  flipper_target = TOP;
  flipper_velocity = 20;
  scorer_target = 0;
  scorer_velocity = 50;
  scoring = false;
  down = 0;
}




void Lift_Systems::setFlipperPower(int power) {
  capFlipperMotor = -power;
}




void Lift_Systems::setCapScorerPower(int power) {
  capScorerMotor = power;
}




void Lift_Systems::driveControl() {

  if (master.get_digital_new_press(DIGITAL_R2)) {
    switch (flipper_target) {
      case TOP :
      flipper_target = FRONT_FLIP;
      flipper_velocity = 100;
      break;
      case FRONT_FLIP :
      flipper_target = BACK_FLIP;
      flipper_velocity = 100;
      break;
      case BACK_FLIP :
      flipper_target = TOP;
      flipper_velocity = 50;
      break;
    }
  }

  capFlipperMotor.move_absolute(flipper_target, flipper_velocity);

  if (master.get_digital_new_press(DIGITAL_B) || master.get_digital(DIGITAL_R1)) {
    scorer_target = 0;
    scorer_velocity = 100;
    scoring = false;
    down = 0;
  }
  else if (master.get_digital_new_press(DIGITAL_A)) {
    scorer_target = HOLD;
    scorer_velocity = 150;
    scoring = false;
    down = 0;
  }
  else if (master.get_digital_new_press(DIGITAL_Y)) {
    scorer_target = DESCORE;
    scorer_velocity = 100;
    scoring = false;
    down = 0;
  }
  else if (master.get_digital_new_press(DIGITAL_X)) {
    scoring = true;
    down = 0;
  }

  if (scoring == true && capScorerMotor.get_position() < (POST - 20)) {
    scorer_target = POST;
    scorer_velocity = 200;
  }
  else if (scoring == true && capScorerMotor.get_position() > (POST - 20)) {
    scorer_target = 0;
    scorer_velocity = 200;
    scoring = false;
  }

  if (scorer_target != 0) {
    capScorerMotor.move_absolute(scorer_target, scorer_velocity);
  }
  else if (scorer_target == 0) {
    if (capScoringArmLimit.get_value() == true) {
      if (down == 0) {
        capScorerMotor = 0;
        down = 1;
      }
    }
    else if (capScoringArmLimit.get_value() == false && down == 0) {
      capScorerMotor = -100;
    }
  }

  if (capScoringArmLimit.get_value() == true) {
    capScorerMotor.tare_position();
  }

}
