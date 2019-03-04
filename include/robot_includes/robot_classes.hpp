#ifndef _ROBOT_CLASSES_HPP_
#define _ROBOT_CLASSES_HPP_



#define IDLE 0
#define DRIVING 1
#define TURNING 2

class Chassis_Systems {
public:
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


private:
  void setLeft(int power);
  void setRight(int power);


  //drive priority to priorities driving or turning
  int drive_priority;
  //target for drive encoder value
  int drive_target;
  //target for gyro value
  int turn_target;
};
#endif
