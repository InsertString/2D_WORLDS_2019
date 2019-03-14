#include "main.h"

void initialize() {
	pros::lcd::initialize();
	vision.set_zero_point(pros::E_VISION_ZERO_CENTER);
	frontLeftDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	backLeftDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	frontRightDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	backRightDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

}

void disabled() {}

void competition_initialize() {}
