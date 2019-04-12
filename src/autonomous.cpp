#include "main.h"


void autonomous() {
  start_auto();
  while (getTime(AUTO_TIMER) < 15000) {
    cap_auto(1);
  }

}
