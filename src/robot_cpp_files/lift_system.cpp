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





void Lift_Systems::driveControl() {
/*
  if (partner.is_connected() == true) {
    if (abs(partner.get_analog(ANALOG_LEFT_Y)) > 20) {

			if (partner.get_analog(ANALOG_LEFT_Y) > 0) {
				capScorerMotor = partner.get_analog(ANALOG_LEFT_Y);
			}
			else if (partner.get_analog(ANALOG_LEFT_Y) < 0 && capScoringArmLimit.get_value() == false) {
				capScorerMotor = partner.get_analog(ANALOG_LEFT_Y);
			}

			arm_position = capScorerMotor.get_position();
		}
		else {
			capScorerMotor.move_absolute(arm_position, 50);
		}




		if (abs(partner.get_analog(ANALOG_RIGHT_Y)) > 20) {

			flipper_power = partner.get_analog(ANALOG_RIGHT_Y);

			if (flipper_power > 100) {
				flipper_power = 100;
			}
			else if (flipper_power < -30) {
				flipper_power = -30;
			}

			capFlipperMotor = flipper_power;
			flipper_position = capFlipperMotor.get_position();
		}
		else {
			capFlipperMotor.move_absolute(flipper_position, 50);
		}
  }
  */
  if (abs(partner.get_analog(ANALOG_LEFT_Y)) > 20) {

    if (partner.get_analog(ANALOG_LEFT_Y) < 0 && capScoringArmLimit.get_value() == true) {
      capScorerMotor = 0;
    }
    else {
      capScorerMotor = partner.get_analog(ANALOG_LEFT_Y);
    }

    arm_position = capScorerMotor.get_position();
  }
  else {
    capScorerMotor.move_absolute(arm_position, 20);
  }






	if (abs(partner.get_analog(ANALOG_RIGHT_Y)) > 20) {

		flipper_power = partner.get_analog(ANALOG_RIGHT_Y);

		if (flipper_power > 100) {
			flipper_power = 100;
		}
		else if (flipper_power < -30) {
			flipper_power = -30;
		}

		capFlipperMotor = flipper_power;
		flipper_position = capFlipperMotor.get_position();
	}
	else {
		capFlipperMotor.move_absolute(flipper_position, 50);
	}

}
