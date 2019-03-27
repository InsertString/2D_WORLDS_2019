#include "main.h"



//controllers
pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);
//~~~~~~~~//


//Motors//
pros::Motor frontRightDriveMotor(FRONT_RIGHT_DRIVE_MOTOR_PORT);
pros::Motor backRightDriveMotor(BACK_RIGHT_DRIVE_MOTOR_PORT);
pros::Motor frontLeftDriveMotor(FRONT_LEFT_DRIVE_MOTOR_PORT);
pros::Motor backLeftDriveMotor(BACK_LEFT_DRIVE_MOTOR_PORT);
pros::Motor catapultMotor(CATAPULT_MOTOR_PORT);
pros::Motor capScorerMotor(CAP_SCORER_MOTOR_PORT);
pros::Motor capFlipperMotor(CAP_FLIPPER_MOTOR_PRORT);
pros::Motor intakeMotor(INTAKE_MOTOR_PORT);
//~~~~~~~//


//Sensors//

pros::ADIGyro gyro(B);
pros::ADIDigitalIn capScoringArmLimit(C);
pros::ADIAnalogIn catapultPot(D);
pros::ADIAnalogIn intakeLight1Sensor(E);
pros::ADIDigitalIn catapultLimit(F);
pros::ADIAnalogIn autonomousSelector(G);
pros::ADIDigitalIn capFlipperLimit(H);


pros::Vision vision(VISION_PORT);




//classes
Chassis_Systems chassis;
Ball_Systems ball_system;
Lift_Systems lift_system;
Vision_Control vision_system;

PID drive_PID;
PID turn_PID;
PID l_d_h_PID;
PID r_d_h_PID;
PID vision_PID;


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


	capFlipperMotor.tare_position();
	capFlipperMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
}

void disabled() {}

void competition_initialize() {}
