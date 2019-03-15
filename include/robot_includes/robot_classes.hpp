#ifndef _ROBOT_CLASSES_HPP_
#define _ROBOT_CLASSES_HPP_




class Chassis_Systems {
public:
  Chassis_Systems();

  #define IDLE 0
  #define DRIVING 1
  #define TURNING 2
  #define HOLDING 3

  /*autoChassisPID//
  -when driving, the gyro will constatly reset
  -when turning the encoders will constantly reset

  -when you set the drive target, it will drive to the desired value
   then stop and hold power until the value is changed
  -setting the dive target will reset the gyro target to 0
   and set the drive priority to driving

  -when you set the turn target, it will turn to the desired value
   then stop and hold power until the value is changed
  -setting the turn target will reset the drive encoders to 0
  and set the drive priority to turning
  */
  void autoChassisPID();
  void setDriveTarget(int target);
  void setTurnTarget(int target);




  /*driveControl
  -when using the joysticks the function will apply truespeed
   and reset the drive encoder values
  -when not using the joysticks the function will apply holding power
  */
  void driveControl();
  void resetChassisSensors(bool reset_gyro);

private:
  #define DRIVE_THRESHOLD 10

  void setLeft(int power);
  void setRight(int power);


  //drive priority to prioritise driving, turning, or holding power
  int drive_priority;
  //target for drive encoder value
  int drive_target;
  //target for gyro value
  int turn_target;

  int left;
  int right;

  int left_drive_hold_state;
  int right_drive_hold_state;
};








class Ball_Systems {
public:

  //catapult macros
  #define TARGET 0
  #define LOAD 1
  #define FIRE 2

  #define STATE 1
  #define LOADED 1
  #define NOT_LOADED 2
  //~~~~~~~~~~~~//

  //Intake macros
  #define UP 1
  #define DOWN 0

  #define FULL 1
  #define EMPTY 0
  //~~~~~~~~~~~//





  Ball_Systems();

  void setCatapultPower(int power);

  void setIntakePower(int power);
  int loaded_ball_count;
  int ball_count;

  //run this function in drive control
  void driveControl();

private:

  int catapult_data[2];


  int intake_state();
  int intake_direction;
  int ball_count_toggle_var_1;
  int ball_count_toggle_var_2;
  int loaded_ball_check;
};






class Lift_Systems {
public:

  #define ZERO_ARM 0
  #define HOLDING_CAP 500
  #define SCORING_CAP 800

  Lift_Systems();

  void setCapScorerPower(int power);
  void setFlipperPower(int power);

  void driveControl();

private:
  int cap_scoring_arm_target;
  int cap_scoring_arm_velocity;
};

#endif
