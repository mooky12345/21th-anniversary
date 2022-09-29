#include<Servo.h>
Servo BASKETServo;
const int BASKETButton=2;
const int right=12;
const int left=11;
const int score=10;
int Score=0;

void setup() {
  Serial.begin(9600);
  BASKETServo.attach(7);
  pinMode(BASKETButton,INPUT_PULLUP);
  pinMode(right,INPUT);
  pinMode(left,INPUT);
}
int i = 0; 
int j = 0;
void loop() {
  if (digitalRead(BASKETButton) == LOW) {
    i+=1;
    } 

  if (i%2==1){
    j=2;
  }
  else{
    BASKETServo.write(90); 
  }
  /*Serial.println("1"); 
  Serial.println(i);
  Serial.println(" ");
  delay(500);*/

//////////////////////////////

  if (digitalRead(left)==1){
    j=1;
    if (j==1){
          BASKETServo.write(0); 
    }
  }
  if (digitalRead(right)==1){
    j=2;
    if (j==2){
          BASKETServo.write(180); 
    }
  }
  /*Serial.println("j"); 
  Serial.println(j);
  Serial.println(" ");
  delay(500);

  
  
  Serial.println("2");
  Serial.println(digitalRead(right));
  Serial.println(" ");
  delay(500);

  Serial.println("3");
  Serial.println(digitalRead(left));
  Serial.println(" ");
  delay(500);*/




  if (digitalRead(score)==1){
    Score+=1;
  }

  //Serial.println(Score);

}
