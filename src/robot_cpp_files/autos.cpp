#include "main.h"
#include "robot_includes/robot_includes.hpp"


//+ distance is intake direction


void flag_auto(int colour) {
  switch (auto_step) {
    case 0 :
    action_1 = auto_turn_swing(900, AUTO_PIVOT_LEFT, 100, 2000);

    if (action_1.return_state == COMPLETE) {
      ball_system.setIntakePower(50);
      //advance_auto_step();
    }
    break;

  }
}













void cap_auto(int colour) {
  switch (auto_step) {
    case 0 :
    action_1 = auto_drive(-1000, 100, 2000);

    if (action_1.return_state == COMPLETE && getTime(AUTO_STEP_TIMER) > 1000) {
      advance_auto_step();
    }
    break;
    case 1 :
    action_1 = auto_drive(1500, 100, 2000);

    if (action_1.return_state == COMPLETE) {
      advance_auto_step();
    }
    break;
    case 2 :
    ball_system.setIntakePower(100);
    break;
  }
}
