#include "main.h"

void initialize() {
	//initialise lcd display
	pros::lcd::initialize();

	//set the vision oriogin too the center of the sensor
	vision.set_zero_point(pros::E_VISION_ZERO_CENTER);

	//set the drive motor brake type too brake
	frontLeftDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	backLeftDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	frontRightDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	backRightDriveMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

	//calibrate the light sensors
	intakeLight1Sensor.calibrate();
}

void disabled() {}

void competition_initialize() {}
