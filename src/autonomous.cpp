#include "main.h"


void autonomous() {
  start_auto();
  while (getTime(AUTO_TIMER) < 15000) {

    switch (auto_step) {
      case 0 :
      placeholder_1 = auto_drive(900, 100);
      if (placeholder_1.return_state == COMPLETE) {
        advance_auto_step();
      }
      break;
      case 1 :
      placeholder_1 = auto_drive(-900, 100);
      break;
    }
  }

}
