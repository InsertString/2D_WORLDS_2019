#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"

//MOTOR PORTS//
#define CATAPULT_MOTOR_PORT 11
#define INTAKE_MOTOR_PORT 20
#define CAP_SCORER_MOTOR_PORT 12
#define CAP_FLIPPER_MOTOR_PRORT 4
#define FRONT_RIGHT_DRIVE_MOTOR_PORT 19
#define BACK_RIGHT_DRIVE_MOTOR_PORT 18
#define FRONT_LEFT_DRIVE_MOTOR_PORT 13
#define BACK_LEFT_DRIVE_MOTOR_PORT 14
//~~~~~~~~~~~~~//



//ADI PORTS//
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
//~~~~~~~~~~~//



//SENSOR PORTS//
#define VISION_PORT 15
//~~~~~~~~~~~~//







#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

//include files//
#include "robot_includes/robot_includes.hpp"

#endif




//Controller externs
extern pros::Controller master;
extern pros::Controller partner;


//motor externs
extern pros::Motor frontRightDriveMotor;
extern pros::Motor backRightDriveMotor;
extern pros::Motor frontLeftDriveMotor;
extern pros::Motor backLeftDriveMotor;
extern pros::Motor catapultMotor;
extern pros::Motor capScorerMotor;
extern pros::Motor capFlipperMotor;
extern pros::Motor intakeMotor;


//sensor externs
extern pros::ADIGyro gyro;
extern pros::ADIAnalogIn intakeLight1Sensor;
extern pros::ADIAnalogIn catapultPot;
extern pros::ADIDigitalIn catapultLimit;
extern pros::ADIAnalogIn capScoringArmLimit;
extern pros::ADIAnalogIn autonomousSelector;
extern pros::Vision vision;


//class externs
extern Chassis_Systems chassis;
extern Ball_Systems ball_system;
extern Lift_Systems lift_system;
extern PID drive_PID;
extern PID turn_PID;
extern PID hold_PID;






#endif  // _PROS_MAIN_H_
