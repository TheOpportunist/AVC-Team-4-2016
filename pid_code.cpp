#include <stdio.h>

//#include <pthread.h>
#include <time.h>
#include <string.h>

// sudo gcc -Wall
extern "C" int init_hardware();
extern "C" int init(int d_lev);

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int color);
extern "C" void set_pixel(int col, int row, char red,char green,char blue);

extern "C" int open_screen_stream();
extern "C" int close_screen_stream();
extern "C" int update_screen();
//extern "C" void GetLine(int row,int threshold);
extern "C" int display_picture(int delay_sec,int delay_usec);
extern "C" int save_picture(char filename[5]);

extern "C" int set_motor(int motor,int speed);

extern "C" int read_analog(int ch_adc);
extern "C" int Sleep(int sec, int usec);
extern "C" int select_IO(int chan, int direct);
extern "C" int write_digital(int chan,char level);
extern "C" int read_digital(int chan);
extern "C" int set_PWM(int chan, int value);

extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);

int main(){
  init(0);
  int sum = 0;
  float kp = 0.5;
  float kd = 0.5;
  int current_error;
  int previous_error; 
  int derivative_signal = 0;
  int proportional_signal = 0;
  int v = -45;
  int i, w, s;

  while(1) {
    take_picture();
    int error_diff = 0;
    int error_period = 1;

    for(i=0; i<320; i++){
      w = get_pixel(i,120,3);
    if(w>127){
       s=1;
    }//;
    else{
       s=0;
    }//;
      sum = sum + (i-160)*s;
    }
    proportional_signal = sum*kp;
    error_diff = current_error-previous_error;
    derivative_signal = (error_diff/error_period)*kd;
    previous_error = current_error;
  
    set_motor(1, v - kp*proportional_signal - kd*derivative_signal);
    set_motor(2, v - kp*proportional_signal - kd*derivative_signal);
  }
  return 0;
}
