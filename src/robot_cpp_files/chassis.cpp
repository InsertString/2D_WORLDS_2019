#include "main.h"
#include "robot_includes/robot_includes.hpp"


//sets the power for the left drive motors
void Chassis_Systems::setLeft(int power) {
  frontLeftDriveMotor = power;
  backLeftDriveMotor = power;
}


//sets the power for the right drive motors
void Chassis_Systems::setRight(int power) {
  frontRightDriveMotor = power;
  backRightDriveMotor = power;
}
