#include "main.h"

int auto_number() {
  int out;

  out = (autonomousSelector.get_value() / 1023.75);

  if (out == 4) {
    out = 3;
  }

  return out;
}

void autonomous() {
  start_auto();
  while (getTime(AUTO_TIMER) < 15001) {
///*



    switch(auto_number()) {
      case 0 :
      cap_auto(RED);
      break;
      case 1 :
      cap_auto(BLUE);
      break;
      case 2 :
      flag_auto(RED);
      break;
      case 3 :
      flag_auto(BLUE);
      break;
    }


    //auto_drive(-2000, 100);
//*/
  //  pros::delay(20);
  //action_1 = auto_turn(900, 100);

//  if (action_1.return_state == COMPLETE) {//    capScorerMotor.move_absolute(400, 200);
  //}

  }

  frontLeftDriveMotor = 0;
  frontRightDriveMotor = 0;
  backLeftDriveMotor = 0;
  backRightDriveMotor = 0;
  intakeMotor = 0;
  catapultMotor = 0;
  capScorerMotor = 0;
  capFlipperMotor = 0;

  pros::delay(20);
}
