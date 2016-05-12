// Code for AVC challenge

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


int v_left = 0;
int v_right = 0;

int main(){
  int init_hardware();
  int i;
  int left;
  int right;
  int middle;
  while(1)
  {
    take_picture();
    left = get_pixel(120, 80, 3);
    middle = get_pixel(120, 160, 3);
    right = get_pixel(120, 240, 3);
    //int sum = 0;
    //for(i=0, i<320, i++) {
    //white = get_pizel(120, i, 3)
    //sum = sum + i*white;
    //}
    if (midlle>left && middle > right){
      v_left = 80;
      v_right = 80;
      set_motor(1, v_left);
      set_motor(2, v_right);
    }
    else if (right>middle && right>left) {
      v_left = 80;
      v_right = 20;
      set_motor(1, v_left);
      set_motor(2, v_right);
    }
    else if (left>middle && left>right) {
      v_left = 20;
      v_right = 80;
      set_motor(1, v_left);
      set_motor(2, v_right);
    }
    sleep(0,500000);
}
