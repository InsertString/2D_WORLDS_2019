#include "main.h"

void opcontrol() {

	while (true) {
/*
		pros::vision_object_s_t flag = vision.get_by_sig(0, 2);


		printf("obj_x = %d obj_y = %d\n", flag.x_middle_coord, flag.y_middle_coord);


		if (master.get_digital(DIGITAL_Y)) {
			if (flag.x_middle_coord > 5 && flag.x_middle_coord < 55) {
				chassis.setLeft(20);
				chassis.setRight(-20);
			}
			else if (flag.x_middle_coord < -5 && flag.x_middle_coord > -55) {
				chassis.setLeft(-20);
				chassis.setRight(20);
			}
			else if (flag.x_middle_coord >= 55) {
				chassis.setLeft(40);
				chassis.setRight(-40);
			}
			else if (flag.x_middle_coord <= -55) {
				chassis.setLeft(-40);
				chassis.setRight(40);
			}
			else {
				chassis.setLeft(0);
				chassis.setRight(0);
			}
		}
		else {
			chassis.setLeft(0);
			chassis.setRight(0);
		}


*/


		ball_system.driveControl();
		lift_system.driveControl();
		chassis.driveControl();


		pros::lcd::print(0, "arm limit = %d", capScoringArmLimit.get_value());
		pros::lcd::print(1, "intake light = %d", intakeLight1Sensor.get_value_calibrated());
		pros::lcd::print(2, "ball count = %d", ball_system.ball_count);
		pros::lcd::print(3, "loaded ball count = %d", ball_system.loaded_ball_count);
		pros::lcd::print(4, "arm_value = %f", capScorerMotor.get_position());


		pros::delay(20);
	}
}
