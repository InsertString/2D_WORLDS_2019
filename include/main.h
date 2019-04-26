#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"

//MOTOR PORTS//
#define CATAPULT_MOTOR_PORT 11
#define INTAKE_MOTOR_PORT 20
#define CAP_SCORER_MOTOR_PORT 12
#define CAP_FLIPPER_MOTOR_PRORT 17
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
#define G 7
#define H 8
//~~~~~~~~~~~//



//SENSOR PORTS//
#define VISION_PORT 15
//~~~~~~~~~~~~//


#define RED 1
#define BLUE 2


#define TOP 0
#define FRONT_FLIP -480
#define BACK_FLIP -550

#define POST 1900
#define HOLD 750
#define DESCORE 1100






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
extern pros::ADIDigitalIn capScoringArmLimit;
extern pros::ADIAnalogIn autonomousSelector;
extern pros::Vision vision;
extern pros::ADIDigitalIn capFlipperLimit;


//class externs
extern Chassis_Systems chassis;
extern Ball_Systems ball_system;
extern Lift_Systems lift_system;
extern Vision_Control vision_system;

//auto PIDS
extern PID auto_drive_PID;
extern PID auto_gyro_correction_PID;

extern PID auto_turn_PID;

extern PID auto_turn_swing_PID;



//drive control PIDS
extern PID l_d_h_PID;
extern PID r_d_h_PID;
extern PID vision_PID;







extern Auto_Action action_1;
extern Auto_Action action_2;
extern Auto_Action action_3;

extern int auto_step;
extern int auto_drive_step;
extern int auto_turn_step;
extern int auto_turn_swing_step;
extern int auto_shoot_step;
extern int auto_move_arm_step;
extern int auto_move_flipper_step;




int auto_number();
void temp_warning();



#endif  // _PROS_MAIN_H_
