//BASKET
#include<Servo.h>
Servo BASKETServo;
const int BASKETButton=1;
const int right=12;
const int left=11;
const int score=10;
int Score=0;

void setup() {
  Serial.begin(9600);
  BASKETServo.attach(A1);
  pinMode(BASKETButton,INPUT_PULLUP);
  pinMode(right,INPUT);
  pinMode(left,INPUT);
}
int i = 0;
void loop() {
  if (digitalRead(BASKETButton) == LOW) {
    i+=1;
    } 
  if (i%2==1){
    BASKETServo.write(180);
  }
  else{
    BASKETServo.write(90); 
  }
//////////////////////////////
  if (digitalRead(right)==1){
    BASKETServo.write(0);
  }
  if (digitalRead(left)==1){
    BASKETServo.write(180);
  }
  if (digitalRead(score)==1){
    Score+=1;
  }
  else{
    Score=Score;
  }
  Serial.println(Score);

}
