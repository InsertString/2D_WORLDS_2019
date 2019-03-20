#include "main.h"

void opcontrol() {

	while (true) {
		
		ball_system.driveControl();
		lift_system.driveControl();
		vision_system.driveControl();
		chassis.driveControl();


		pros::lcd::print(0, "arm limit = %d", capScoringArmLimit.get_value());
		pros::lcd::print(1, "intake light = %d", intakeLight1Sensor.get_value_calibrated());
		pros::lcd::print(2, "ball count = %d", ball_system.ball_count);
		pros::lcd::print(3, "loaded ball count = %d", ball_system.loaded_ball_count);
		pros::lcd::print(4, "arm_value = %f", capScorerMotor.get_position());


		pros::delay(20);
	}
}
