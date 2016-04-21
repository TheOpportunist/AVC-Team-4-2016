// Code for AVC challenge

#include <stdio.h>
#include <time.h>

// load methods from ENGR101 lib
extern "C" int init_hardware();
extern "C" int read_analog(int ch_adc);
extern "C" int sleep(int sec, int usec);
extern "C" int write_digital(int chan, char level);
extern "C" int set_motor(int motor, int dir, int speed);

int main {
  init_hardware();
  //
  return 0;
  }
