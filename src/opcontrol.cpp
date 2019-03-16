#include "main.h"

void opcontrol() {

	while (true) {
		chassis.driveControl();
		ball_system.driveControl();
		lift_system.driveControl();


		pros::lcd::print(0, "arm limit = %d", capScoringArmLimit.get_value());
		pros::lcd::print(1, "intake light = %d", intakeLight1Sensor.get_value_calibrated());
		pros::lcd::print(2, "ball count = %d", ball_system.ball_count);
		pros::lcd::print(3, "loaded ball count = %d", ball_system.loaded_ball_count);
/*
		if (i == 1 && catapultPot.get_value() == false) {
			catapultMotor = 127;
		}
	 	else if (master.get_digital(DIGITAL_R2)) {
			catapultMotor = 127;
			i = 0;
		}
		else if (master.get_digital(DIGITAL_R1)) {
			i = 1;
		}
		else {
			catapultMotor = 0;
		}




		if (master.get_digital(DIGITAL_L1)) {
			intakeMotor = -127;
		}
		else if (master.get_digital(DIGITAL_L2)) {
			intakeMotor = 127;
		}
		else {
			intakeMotor = 0;
		}



		if (master.get_digital(DIGITAL_X)) {
			capScorerMotor = 127;
			i = 15;
		}
		else if (master.get_digital(DIGITAL_B)) {
			capScorerMotor = -127;
			i = 0;
		}
		else {
			capScorerMotor = i;
		}
*/


		pros::delay(20);
	}
}
