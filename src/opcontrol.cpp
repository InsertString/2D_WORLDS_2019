#include "main.h"


int timer_statred;
void temp_warning() {
	if (frontLeftDriveMotor.get_temperature() > 55 || frontRightDriveMotor.get_temperature() > 55 || backLeftDriveMotor.get_temperature() > 55 || backRightDriveMotor.get_temperature() > 55 || catapultMotor.get_temperature() > 55 || intakeMotor.get_temperature() > 55 || capScorerMotor.get_temperature() > 55 || capFlipperMotor.get_temperature() > 55) {
		if (timer_statred == 0) {
			master.rumble(". . . - - - . . .     . . . - - - . . .     . . . - - - . . .     . . . - - - . . .");
			master.print(0, 0, "!!!STOP DRIVING!!!");
			timer_statred = 1;
		}
	}
	else {
		timer_statred = 0;
	}
}






void opcontrol() {



	while (true) {

		temp_warning();

		if (master.get_digital(DIGITAL_LEFT) && master.get_digital(DIGITAL_RIGHT)) {
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
		}
		else {

			ball_system.driveControl();
			lift_system.driveControl();
			vision_system.driveControl();
			chassis.driveControl();


			switch(auto_number()) {
				case 0 :
				pros::lcd::print(0, " RED CAP AUTO ");
				break;
				case 1 :
				pros::lcd::print(0, " BLUE CAP AUTO");
				break;
				case 2 :
				pros::lcd::print(0, " RED FLAG AUTO");
				break;
				case 3 :
				pros::lcd::print(0, "BLUE FLAG AUTO");
				break;
			}
		}





		pros::delay(20);
	}
}
