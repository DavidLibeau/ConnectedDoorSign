/**
*
* Project       : Connected Door Sign
* Version       : V1.0
* By            : David Libeau (davidlibeau.fr)
* License       : CC-BY-NC-SA
* GitHub        : https://github.com/DavidLibeau/ConnectedDoorSign
* Instructable  : http://www.instructables.com/id/Connected-Door-Sign/
*
**/
#include <epd.h>

const int led = 13;
const int btn = 8;
int buttonState = 0;
int choice=0;
int breakloop=0;


void changetoNoEntry(){
  epd_wakeup();
  epd_clear();

  epd_set_color(BLACK, WHITE);
  epd_set_en_font(ASCII64);
  epd_disp_string("No Entry !  :(", 250, 520);

  epd_disp_bitmap("NO.BMP", 150, 0);
  
  epd_udpate();
  delay(100);
  epd_enter_stopmode();
}

void changetoWelcome(){
  epd_wakeup();
  epd_clear();

  epd_set_color(BLACK, WHITE);
  epd_set_en_font(ASCII64);
  epd_disp_string("Welcome !  :)", 250, 520);

  epd_disp_bitmap("W.BMP", 150, 0);

  epd_udpate();
  epd_enter_stopmode();
}


void setup(){
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  pinMode(btn, INPUT);
  
  epd_init();
  epd_wakeup();
  epd_set_memory(MEM_NAND);
  epd_load_pic();
}

void loop(){

  while(!breakloop){
    buttonState = digitalRead(btn);
    if (buttonState == HIGH) {
      digitalWrite(led, LOW);
    } else {
      if(choice==0){
        choice=1;
      }else{
        choice=0;
      }
      digitalWrite(led, HIGH);
      breakloop=1;
    }
  }

  if(choice){
    changetoWelcome();
  }else{
    changetoNoEntry();
  }
  breakloop=0;
}


