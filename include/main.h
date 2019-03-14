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



//SENSOR PORTS//
#define GYRO_PORT 0
#define INTAKE_LIGHT_1_SENSOR_PORT 1
#define INTAKE_LIGHT_2_SENSOR_PORT 2
#define CATAPULT_POT_PORT 4
#define CAP_SCORER_ARM_LIMIT_PORT 4
#define AUTONOMOUS_SELECTOR_PORT 5
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
extern pros::ADIAnalogIn intakeLight2Sensor;
extern pros::ADIDigitalIn catapultPot;
extern pros::ADIAnalogIn capScoringArmLimit;
extern pros::ADIAnalogIn autonomousSelector;
extern pros::Vision vision;


//class externs
extern Chassis_Systems chassis;
extern PID drive_PID;
extern PID turn_PID;
extern PID hold_PID;






#endif  // _PROS_MAIN_H_
