//HAND
#include<Servo.h>
Servo HANDServo;
const int HANDButton=2;
const int forward=9;
const int backward=8;

void setup() {
  Serial.begin(9600);
  HANDServo.attach(A2);
  pinMode(HANDButton,INPUT_PULLUP);
  pinMode(forward,INPUT);
  pinMode(backward,INPUT);
}
int j = 0;
void loop() {
  if (digitalRead(HANDButton) == LOW) {
    j+=1;
    } 
  if (j%2==1){
    HANDServo.write(180);
  }
  else{
    HANDServo.write(90); 
  }
////////////////////////////////
  if (digitalRead(forward)==1){
    HANDServo.write(0);
  }
  delay(3000);
  if (digitalRead(backward)==1){
    HANDServo.write(180);
  }
  delay(3000);

}
