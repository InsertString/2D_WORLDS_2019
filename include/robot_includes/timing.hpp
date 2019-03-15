#ifndef _TIMING_H_
#define _TIMING_H_


#define LEFT_DRIVE_HOLD_TIMER 10
#define RIGHT_DRIVE_HOLD_TIMER 11


void startTimer(int slot);
int getTime(int slot);

#endif
