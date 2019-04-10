#include "main.h"
#include "robot_includes/robot_includes.hpp"



Chassis_Systems::Chassis_Systems() {
	drive_priority = IDLE;
	drive_target = 0;
	turn_target = 0;
	left_drive_hold_state = IDLE;
	right_drive_hold_state = IDLE;
	left = 0;
	right = 0;


	l_d_h_PID.set_PID_vars(5, 0, 0, 0);
	l_d_h_PID.target = 0;

	r_d_h_PID.set_PID_vars(5, 0, 0, 0);
	r_d_h_PID.target = 0;

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






void Chassis_Systems::requestDrivePriority(int class_system) {
	drive_system_request = class_system;
}





void Chassis_Systems::request_left(int power) {
	left = power;
}





void Chassis_Systems::request_right(int power) {
	right = power;
}





double Chassis_Systems::right_encoder_val() {
	return frontRightDriveMotor.get_position();
}






void Chassis_Systems::driveControl() {


	if (drive_system_priority == DRIVE_PRIORITY_CHASSIS) {
		//profiles the motor power to follow a more linear curve
	  if (abs(master.get_analog(ANALOG_LEFT_Y)) > DRIVE_THRESHOLD) {
	    left = master.get_analog(ANALOG_LEFT_Y) > 0 ? TrueSpeedArray[abs(master.get_analog(ANALOG_LEFT_Y))] : -TrueSpeedArray[abs(master.get_analog(ANALOG_LEFT_Y))];
	    drive_priority = DRIVING;
			left_drive_hold_state = DRIVING;
	  }
	  else {
			if (left_drive_hold_state == DRIVING) {
				left = 0;
				resetChassisSensors(false);
				left_drive_hold_state = IDLE;
			}
	  }




		//profiles the motor power to follow a more linear curve
		if (abs(master.get_analog(ANALOG_RIGHT_Y)) > DRIVE_THRESHOLD) {
			right = master.get_analog(ANALOG_RIGHT_Y) > 0 ? TrueSpeedArray[abs(master.get_analog(ANALOG_RIGHT_Y))] : -TrueSpeedArray[abs(master.get_analog(ANALOG_RIGHT_Y))];
			drive_priority = DRIVING;
			right_drive_hold_state = DRIVING;
		}
		else {
			if (right_drive_hold_state == DRIVING) {
				right = 0;
				resetChassisSensors(false);
				right_drive_hold_state = IDLE;
			}
	  }



		if (master.get_digital(DIGITAL_Y)) {
			right_drive_hold_state = HOLDING;
			left_drive_hold_state = HOLDING;
			l_d_h_PID.current = frontLeftDriveMotor.get_position();
			left = l_d_h_PID.output(127);
			r_d_h_PID.current = frontRightDriveMotor.get_position();
			right = r_d_h_PID.output(127);
		}

	}



	if ((abs(master.get_analog(ANALOG_RIGHT_Y)) < DRIVE_THRESHOLD) && (abs(master.get_analog(ANALOG_LEFT_Y)) < DRIVE_THRESHOLD)) {
		drive_system_priority = drive_system_request;
	}
	else {
		drive_system_priority = DRIVE_PRIORITY_CHASSIS;
		drive_system_request = DRIVE_PRIORITY_CHASSIS;
	}





	setRight(right);
	setLeft(left);
}
