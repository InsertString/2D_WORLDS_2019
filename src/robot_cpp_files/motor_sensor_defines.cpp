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
pros::ADIAnalogIn intakeLight1Sensor(A);
pros::ADIAnalogIn intakeLight2Sensor(E);
pros::ADIDigitalIn catapultPot(F);
pros::ADIAnalogIn capScoringArmLimit(C);
pros::ADIAnalogIn autonomousSelector(B);
pros::Vision vision(VISION_PORT);




//classes
Chassis_Systems chassis;

PID drive_PID;
PID turn_PID;
PID hold_PID;
