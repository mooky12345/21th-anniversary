#include <Servo.h>
#define BUTTON_PIN_UP 6
Servo upservo_1;
Servo upservo_2;
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN_UP,INPUT_PULLUP);
  upservo_1.attach(A0);
  upservo_2.attach(A3);
}
int k=0;
int upswitch=0;
void loop() {
  if(digitalRead(BUTTON_PIN_UP)==HIGH and k!=1 and upswitch==0){ //按鈕按下正轉,上升
     k=1; 
     upservo_1.write(180);                     
  }
  if(digitalRead(BUTTON_PIN_UP)==HIGH and k==1 and upswitch==0){ //停
      k=0;
      upswitch=1;
  }
    

}
