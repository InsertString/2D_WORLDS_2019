#include "main.h"
#include "robot_includes/robot_includes.hpp"

#define TOP 0
#define FRONT_FLIP -450
#define BACK_FLIP -550

Lift_Systems::Lift_Systems() {
  flipper_target = TOP;
  flipper_velocity = 20;
  scorer_target = 0;
  scorer_velocity = 50;
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
      flipper_velocity = 50;
      break;
      case FRONT_FLIP :
      flipper_target = BACK_FLIP;
      flipper_velocity = 50;
      break;
      case BACK_FLIP :
      flipper_target = TOP;
      flipper_velocity = 90;
      break;
    }
  }

  capFlipperMotor.move_absolute(flipper_target, flipper_velocity);

 if (master.get_digital_new_press(DIGITAL_B)) {
   scorer_target = 0;
   scorer_velocity = 200;
 }
 else if (master.get_digital_new_press(DIGITAL_A)) {
   scorer_target = 750;
   scorer_velocity = 150;
 }
 else if (master.get_digital_new_press(DIGITAL_X)) {
   scorer_target = 1900;
   scorer_velocity = 200;
 }

 capScorerMotor.move_absolute(scorer_target, scorer_velocity);

}
