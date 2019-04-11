#include "main.h"

void opcontrol() {



	while (true) {

		ball_system.driveControl();
		lift_system.driveControl();
		vision_system.driveControl();
		chassis.driveControl();

		pros::lcd::print(0, "front encoder value = %f", frontRightDriveMotor.get_position());
		pros::lcd::print(1, "error = %f", r_d_h_PID.error());
		pros::lcd::print(2, "current = %f", r_d_h_PID.current);

		pros::delay(20);
	}
}
