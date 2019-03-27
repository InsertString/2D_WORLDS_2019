#include "main.h"
#include "robot_includes/robot_includes.hpp"





Ball_Systems::Ball_Systems() {
  catapult_data[TARGET] = LOAD;
  catapult_data[STATE] = NOT_LOADED;
  intake_direction = 0;
  ball_count = 0;
  loaded_ball_count = 0;
  ball_count_toggle_var_1 = 0;
  ball_count_toggle_var_2 = 0;
  loaded_ball_check = 0;
}






void Ball_Systems::setIntakePower(int power) {
  intakeMotor = -power;
}





void Ball_Systems::setCatapultPower(int power) {
  catapultMotor = power;
}





int Ball_Systems::intake_state() {
  int return_state;
  return_state = (intakeLight1Sensor.get_value_calibrated() < -0) ? FULL : EMPTY;
  return return_state;
}





void Ball_Systems::driveControl() {


  //CATAPULT CODE//

  catapult_data[STATE] = (catapultLimit.get_value() == true && catapultPot.get_value() < 1200) ? LOADED : NOT_LOADED;

  if ((master.get_digital_new_press(DIGITAL_R1) && catapult_data[STATE] == LOADED && abs(loaded_ball_count) > 0) || (master.get_digital_new_press(DIGITAL_UP))) {
    catapult_data[TARGET] = FIRE;
    ball_count = intakeLight1Sensor.get_value() < -100 ? 1 : 0;
    loaded_ball_count = 0;
  }



  if (catapult_data[TARGET] == FIRE) {
    if (catapult_data[STATE] == LOADED) {
      setCatapultPower(127);
    }
    else {
      setCatapultPower(0);
      catapult_data[TARGET] = LOAD;
    }
  }
  else if (catapult_data[TARGET] == LOAD) {
    if (catapult_data[STATE] == NOT_LOADED) {
      setCatapultPower(127);
    }
    else {
      setCatapultPower(0);
    }
  }
  //~~~~~~~~~~~~~~~~//


  //INTAKE CODE//

  if (catapult_data[STATE] == LOADED) {

    if (master.get_digital(DIGITAL_L1)) {
      setIntakePower(127);
      intake_direction = UP;
    }
    else if (master.get_digital(DIGITAL_L2)) {
      setIntakePower(-127);
      intake_direction = DOWN;
    }
    else {
      setIntakePower(0);
    }

  }
  //~~~~~~~~~~~~~~~~~//



  //BALL COUNTING CODE//

  /*
  There are three possible outcomes when a ball is intaked
  -the ball remains in the intake
  -the ball is intaked into the catapult
  -the ball is outaked from the robot
  */

  /*
  this first if statement is resposable for detecting the ball
  when the ball is first detected it has only two origins
    1. it was intaked into the robot therefore the total number
       of balls in the robot increases and the number of loaded balls
       remains the same.
    2. it was unloaded from the catapult therefore the total number
       of balls in the robot remains the same and the number of loaded
       balls decreases.
  */
  if (intake_state() == FULL) {
    for (; ball_count_toggle_var_1 < 1; ball_count_toggle_var_1++) {
      //this variable says that there is currently a ball detected.
      loaded_ball_check = 1;

      //checks the direction of the intake either up or down
      if (intake_direction == UP) {
        //because the intake is going up, we know that it has to have come from the field
        ball_count++;//increase ball_count by 1
      }
      else if (intake_direction == DOWN) {
        //because the intake is going down, we know that it has to have come from the catapult
        loaded_ball_count--;//decrease loaded_ball_count by 1
      }
    }
  }

  /*
  this second if statement checks what happens after the ball has been detected
  there are three possible outcomes
    1. the ball remains inside the intake therefore no values change
    2. the ball will be intaked into the catapult therefore the total ball count
       remains the same and the loaded ball count increases.
    3. the ball will be outaked therefore the total ball count decreases and
       the loaded ball count remains the same
  */
  if (loaded_ball_check == 1) {
    //checks for when the ball leaves sight of the line follower
    if (intake_state() == EMPTY) {
      for (; ball_count_toggle_var_2 < 1; ball_count_toggle_var_2++) {
        //checks the direction of the intake either up or down
        if (intake_direction == UP) {
          //because the intake is going up we know that the ball is being loaded into the catapult
          loaded_ball_count++;//increase loaded_ball_count by 1
        }
        else if (intake_direction == DOWN) {
          //because the intake is going down we know that the ball is being outaked out of the robot
          ball_count--;//decrease ball_count by 1
        }

        //the ball is no longer being detected so this should not run again until another ball cycles through the system
        loaded_ball_check = 0;
      }
    }
  }
  else if (loaded_ball_check == 0) {
    //reset the toggle variables so that they can be used for the next cycle of balls
    ball_count_toggle_var_1 = 0;
    ball_count_toggle_var_2 = 0;
  }
  //~~~~~~~~~~~~~~//
}
