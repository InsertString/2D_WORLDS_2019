#include "main.h"
#include "robot_includes/robot_includes.hpp"



Chassis_Systems::Chassis_Systems() {
	drive_priority = IDLE;
	drive_target = 0;
	turn_target = 0;
}




const unsigned int TrueSpeedArray[128] = {
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	0, 0, 0, 0, 0, 22, 22, 23, 24, 24,
	25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
	28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
	33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
	37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
	41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
	46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
	52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
	71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
	80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
	88, 89, 89, 90, 90,127,127,127
};



//sets the power for the left drive motors
void Chassis_Systems::setLeft(int power) {
  frontLeftDriveMotor = power;
  backLeftDriveMotor = power;
}


//sets the power for the right drive motors
void Chassis_Systems::setRight(int power) {
  frontRightDriveMotor = -power;
  backRightDriveMotor = -power;
}



void Chassis_Systems::resetChassisSensors(bool reset_gyro) {
  frontRightDriveMotor.tare_position();
  backRightDriveMotor.tare_position();

  frontLeftDriveMotor.tare_position();
  backLeftDriveMotor.tare_position();

  if (reset_gyro == true) {
    gyro.reset();
  }
}








void Chassis_Systems::driveControl() {


	//profiles the motor power to follow a more linear curve
  if (abs(master.get_analog(ANALOG_LEFT_Y)) > DRIVE_THRESHOLD) {
    left = master.get_analog(ANALOG_LEFT_Y) > 0 ? TrueSpeedArray[abs(master.get_analog(ANALOG_LEFT_Y))] : -TrueSpeedArray[abs(master.get_analog(ANALOG_LEFT_Y))];
    drive_priority = DRIVING;
		setLeft(left);
		left_drive_hold_state = DRIVING;
  }
  else {
		if (left_drive_hold_state == DRIVING) {
			resetChassisSensors(false);
			left_drive_hold_state = IDLE;
			startTimer(LEFT_DRIVE_HOLD_TIMER);
		}
		else if (left_drive_hold_state == IDLE) {
			left = 0;
			left_drive_hold_state = (getTime(LEFT_DRIVE_HOLD_TIMER) > 100) ? HOLDING : IDLE;
		}
		else if (left_drive_hold_state == HOLDING) {
		//	frontLeftDriveMotor.move_absolute(0, 50);
		//	backLeftDriveMotor.move_absolute(0, 50);
		}
  }




	//profiles the motor power to follow a more linear curve
	if (abs(master.get_analog(ANALOG_RIGHT_Y)) > DRIVE_THRESHOLD) {
		right = master.get_analog(ANALOG_RIGHT_Y) > 0 ? TrueSpeedArray[abs(master.get_analog(ANALOG_RIGHT_Y))] : -TrueSpeedArray[abs(master.get_analog(ANALOG_RIGHT_Y))];
		drive_priority = DRIVING;
		setRight(right);
	}
	else {
		if (right_drive_hold_state == DRIVING) {
			resetChassisSensors(false);
			right_drive_hold_state = IDLE;
			startTimer(RIGHT_DRIVE_HOLD_TIMER);
		}
		else if (right_drive_hold_state == IDLE) {
			left = 0;
			right_drive_hold_state = (getTime(RIGHT_DRIVE_HOLD_TIMER) > 100) ? HOLDING : IDLE;
		}
		else if (right_drive_hold_state == HOLDING) {
		//	frontRightDriveMotor.move_absolute(0, 50);
		//	backRightDriveMotor.move_absolute(0, 50);
		}
  }


}
