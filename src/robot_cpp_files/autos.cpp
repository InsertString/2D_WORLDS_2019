#include "main.h"
#include "robot_includes/robot_includes.hpp"


//+ distance is intake direction


void flag_auto(int colour) {
  switch (auto_step) {
    case 0 :
    action_1 = auto_drive(2400, 100, 3000);
    ball_system.setIntakePower(-100);

    if (abs(action_1.public_value) < 150 && getTime(AUTO_STEP_TIMER) > 200) {
      capFlipperMotor.move_absolute(FRONT_FLIP, 100);
    }

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 1 :
    action_1 = auto_drive(-2380, 100, 2000);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 2 :

    action_1 = colour == RED ? auto_turn(-930, 100, 1200) : auto_turn(960, 100, 1200);
    capFlipperMotor.move_absolute(0, 100);

    if (action_1.return_state == COMPLETE && getTime(AUTO_STEP_TIMER) > 100) {
      advance_auto_step();
    }
    break;
    case 3 :
    action_1 = auto_drive(-300, 100, 500);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 4 :
    action_1 = auto_shoot(2000);
    capScorerMotor.move_absolute(HOLD, 200);

    if (action_1.public_value > 0) {
      action_2 = auto_drive(-2900, 100, 3000);
    }

    if (action_2.return_state == COMPLETE && capScorerMotor.get_position() > (HOLD - 10)) {
      advance_auto_step();
    }
    break;
    case 5 :
    advance_auto_step();
    break;
    case 6 :
    action_1 = auto_drive(2100, 100, 4000);
    capScorerMotor.move_absolute(0, 100);

    if (action_1.return_state == COMPLETE && capScoringArmLimit.get_value() == true) {
      advance_auto_step();
      ball_system.setIntakePower(0);
    }
    break;
    case 7 :
    colour == RED ? action_1 = auto_turn(930, 100, 1500) : auto_turn(-930, 100, 1500);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 8 :
    capFlipperMotor.move_absolute(BACK_FLIP, 100);

    if (capFlipperMotor.get_position() < (BACK_FLIP + 10)) {
      advance_auto_step();
    }
    break;
    case 9 :
    action_1 = auto_drive(-1000, 60, 2000);

    if (abs(action_1.public_value) < 500) {
      capFlipperMotor.move_absolute(0, 50);
    }

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 10 :
    
    break;
  }
}





























void flag_wait(int colour, int timer) {
  switch (auto_step) {
    case 0 :
    action_1 = auto_drive(2400, 100, 3000);
    ball_system.setIntakePower(-100);

    if (abs(action_1.public_value) < 150 && getTime(AUTO_STEP_TIMER) > 200) {
      capFlipperMotor.move_absolute(FRONT_FLIP, 100);
    }

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 1 :
    action_1 = auto_drive(-2380, 100, 2000);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 2 :

    action_1 = colour == RED ? auto_turn(-930, 100, 1200) : auto_turn(960, 100, 1200);
    capFlipperMotor.move_absolute(0, 100);

    if (action_1.return_state == COMPLETE && getTime(AUTO_STEP_TIMER) > 100) {
      advance_auto_step();
    }
    break;
    case 3 :
    action_1 = auto_drive(-300, 100, 500);

    if (action_1.return_state == COMPLETE && getTime(AUTO_TIMER) > timer) {
      advance_auto_step();
    }
    break;
    case 4 :
    action_1 = auto_shoot(2000);
    capScorerMotor.move_absolute(HOLD, 200);

    if (action_1.public_value > 0) {
      action_2 = auto_drive(-2900, 100, 3000);
    }

    if (action_2.return_state == COMPLETE && capScorerMotor.get_position() > (HOLD - 10)) {
      advance_auto_step();
    }
    break;
    case 5 :
    advance_auto_step();
    break;
    case 6 :
    action_1 = auto_drive(2100, 100, 4000);
    capScorerMotor.move_absolute(0, 100);
    capFlipperMotor.move_absolute(BACK_FLIP, 100);

    if (action_1.return_state == COMPLETE && capScoringArmLimit.get_value() == true) {
      advance_auto_step();
      ball_system.setIntakePower(0);
    }
    break;
    case 7 :
    action_1 = colour == RED ? auto_turn_swing(1500, AUTO_PIVOT_RIGHT, 70, 2000) : auto_turn_swing(-1500, AUTO_PIVOT_LEFT, 70, 2000);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 8 :
    capScorerMotor.move_absolute(0, 100);
    capFlipperMotor.move_absolute(0, 50);

    action_1 = auto_drive(300, 100, 500);

    if (action_1.return_state == COMPLETE) {
      if (getTime(AUTO_STEP_TIMER) > 800) {
        advance_auto_step();
      }
    }
    break;
    case 9 :
    advance_auto_step();
    break;
    case 10 :
    capFlipperMotor.move_absolute(0, 200);

    if (capFlipperMotor.get_position() > -10) {
      advance_auto_step();
    }
    break;
    case 11 :
    action_1 = auto_drive(-500, 100, 500);
    if (action_1.return_state == COMPLETE) {
      capFlipperMotor.move_absolute(BACK_FLIP, 70);
      if (capFlipperMotor.get_position() < (BACK_FLIP + 10)) {
        advance_auto_step();
      }
    }
    break;
    case 12 :
    action_1 = auto_drive(1000, 100, 1000);

    if (action_1.return_state == COMPLETE) {
      capFlipperMotor.move_absolute(0, 50);

      if (capFlipperMotor.get_position() > -10) {
        advance_auto_step();
      }
    }
    break;
    case 13 :
    colour == RED ? action_1 = auto_turn(1900, 100, 2000) : auto_turn(-1900, 100, 2000);
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 14 :
    action_1 = auto_drive(-300, 100, 500);
    if (getTime(AUTO_TIMER) > 14500) {
      ball_system.setCatapultPower(127);
    }
    break;
  }
}

























void cap_auto(int colour) {
  switch (auto_step) {
    case 0 :
    capScorerMotor.move_absolute(HOLD, 200);

    if (capScorerMotor.get_position() > (HOLD - 10)) {
      action_1.public_value = 1;
    }

    if (action_1.public_value == 1) {

      if (capFlipperLimit.get_value() != true) {
        capScorerMotor = -100;
      }
      else {
        capScorerMotor = 0;
      }

      action_2 = auto_drive(-2600, 100, 2000);

      if (action_2.return_state == COMPLETE) {
        advance_auto_step();
      }
    }
    break;
    case 1 :
    capScorerMotor.move_absolute(HOLD, 100);

    if (capScorerMotor.get_position() > (HOLD - 10)) {
      action_1.public_value = 1;
    }

    if (action_1.public_value == 1) {
      action_2 = auto_drive(1300, 100, 2000);

      if (action_2.return_state == COMPLETE) {
        advance_auto_step();
      }
    }
    break;
    case 2 :
    action_1 = colour == RED ? auto_turn(1200, 60, 1300) : auto_turn(-1200, 70, 1500);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 3 :
    action_3 = auto_drive(600, 100, 1000);

    if (abs(action_3.public_value) < 150) {
      capScorerMotor.move_absolute(POST, 200);

      if (capScorerMotor.get_position() > (POST - 10)) {
        action_1.public_value = 1;
      }

      if (action_1.public_value == 1) {
        advance_auto_step();
      }
    }
    break;
    case 4 :
    action_3 = auto_drive(-1500, 100, 1000);
    capScorerMotor.move_absolute(500, 200);

    if (action_3.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 5 :
    action_1 = colour == RED ? auto_turn(900, 100, 1000) :  auto_turn(-900, 100, 1000);
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 6 :
    action_1 = auto_drive(1000, 70, 1000);
    intakeMotor = -127;
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 7 :
    action_1 = colour == RED ? auto_turn(-900, 100, 1000) : auto_turn(900, 100, 1000);
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 8 :
    action_1 = auto_drive(-3000, 127, 10000);
    intakeMotor = 0;
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
  }
}
