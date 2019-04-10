#include "main.h"

Auto_Action a;

void autonomous() {
  start_auto();
  while (getTime(AUTO_TIMER) < 15000) {
      auto_drive(1000, 70);

  }

}
