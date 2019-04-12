#include "main.h"
#include "robot_includes/robot_includes.hpp"


//+ distance is intake direction
void cap_auto(int colour) {
  switch (auto_step) {
    case 0 :

    action_1 = auto_move_arm(700, 200);

    if (action_1.return_state == COMPLETE) {
      action_2 = auto_drive(-2800, 60);
      capScorerMotor.move_absolute(0, 200);
    }

    if (action_2.return_state == COMPLETE || getTime(AUTO_STEP_TIMER) > 4000) {
      advance_auto_step();
    }
    break;
    case 1 :
    action_1 = auto_move_arm(750, 100);

    if (action_1.return_state == COMPLETE) {
      action_2 = auto_drive(1200, 60);

      if (action_2.return_state == COMPLETE) {
        advance_auto_step();
      }
    }
    break;
    case 2 :
    action_1 = auto_turn(1200, 40);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 3 :
    action_1 = auto_drive(1000, 50);

    if (abs(action_1.public_value) < 200) {
      action_2 = auto_move_arm(1900, 100);
    }

    if (action_2.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 4 :
    action_1 = auto_move_arm(400, 200);

    if (action_1.public_value < 1500) {
      action_2 = auto_drive(-1500, 100);
    }

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 5 :
    action_1 = auto_turn(-900, 60);
    ball_system.setIntakePower(100);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 6 :
    action_1 = auto_drive(1500, 70);

    if (abs(action_1.public_value) < 50) {
      action_2 = auto_move_flipper(-200, 100);
    }

    if (action_2.return_state == COMPLETE && action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 7 :
    action_1 = auto_drive(-1000, 70);
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 8 :
    action_1 = auto_turn(900, 60);
    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 9 :
    action_1 = auto_drive(2000, 100);
    break;
  }
}
