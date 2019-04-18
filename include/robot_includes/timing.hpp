#ifndef _TIMING_H_
#define _TIMING_H_


#define AUTO_TIMER 0
#define AUTO_STEP_TIMER 1

#define AUTO_DRIVE_TIMEOUT 2
#define AUTO_DRIVE_EXIT 3

#define AUTO_TURN_TIMEOUT 4
#define AUTO_TURN_EXIT 5

#define AUTO_TURN_SWING_TIMEOUT 6
#define AUTO_TURN_SWING_EXIT 7

#define AUTO_SHOOT_TIMEOUT 8

#define AUTO_MOVE_ARM_TIMEOUT 9
#define AUTO_MOVE_FLIPPER_TIMEOUT 10

#define SOS_TIMER 11

#define AUTO_SHOOT_EXIT 12


void startTimer(int slot);
int getTime(int slot);

#endif
