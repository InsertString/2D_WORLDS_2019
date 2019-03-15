#include "main.h"

void opcontrol() {
	int i;
	int a;
	int b;

	while (true) {
		chassis.driveControl();

		pros::lcd::print(0, "cat pot = %d", catapultPot.get_value());

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



		pros::delay(20);
	}
}
