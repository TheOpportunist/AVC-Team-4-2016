#include <stdio.h>
#include <time.h>
#include <string.h>
//#include <pthread.h>

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

//extern "C" int init(int d_lev);
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);

int main() {
  init(0);
  int i;
  int v_left = -190;
  int v_right = -215;
  
  /**
   //connects to server with the ip address 192.168.1.2
   connect_to_server("130.195.6.196", 1024);
   //sends a message to the connected server
   send_to_server("Please");
   //receives message from the connected server
   char message[24];
   receive_from_server(message); //this may be buggy!
   printf("%s", message);
   send_to_server(message);
   **/
  
  while(true) {
    take_picture();
    printf("picture taken\n");
    
    //left = get_pixel(80, 120, 3);
    //middle = get_pixel(160, 120, 3);
    //right = get_pixel(240, 120, 3);
    //printf(" left=%d middle=%d right=%d \n", left, middle, right);
    
    set_motor(1, v_right);
    set_motor(2, v_left);
    
    printf(" v_left=%d v_right=%d \n", v_left, v_right);
  }
  return 0;
}
