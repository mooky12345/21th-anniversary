#define BUTTON_PIN_board 10         //籃框按鈕   
#define sw_PIN_board_LEFT 2         //籃框左側微動
#define sw_PIN_board_RIGHT 3        //籃框右側微動


#define BUTTON_PIN_hand 5           //手臂按鈕
#define sw_PIN_hand_FRONT 6         //手臂前側微動
#define sw_PIN_hand_BACK 7          //手臂後側微動
//#define BUTTON_PIN_ascent 11        //上升按鈕

int test;
// i = orad  j = hand  l = ascent
#include<Servo.h>
Servo boardservo;                   //籃框馬達
Servo handservo;                    
//Servo ascentservo;
void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN_board,INPUT_PULLUP); 
  pinMode(sw_PIN_board_LEFT,INPUT_PULLUP);                 
  pinMode(sw_PIN_board_RIGHT,INPUT_PULLUP);
  pinMode(BUTTON_PIN_hand,INPUT_PULLUP);
  pinMode(sw_PIN_hand_FRONT,INPUT_PULLUP);
  pinMode(sw_PIN_hand_BACK,INPUT_PULLUP);
  
  //pinMode(BUTTON_PIN_ascent,INPUT_PULLUP);
  boardservo.attach(8);
  handservo.attach(9);
  //ascentservo.attach(10); 
}  
int present[2] = {HIGH, HIGH};                                          
int i = 0,j = 0,pos1 = 90,pos2 = 90 ,in = 0, in1 = 0 ; 


int previous[2] = {HIGH, HIGH};

void loop(){


  present[0] = digitalRead(BUTTON_PIN_board);
  present[1] = digitalRead(BUTTON_PIN_hand);
  
  /*while (true){
  for (int p=0;p<=2;p++){
    Serial.println(p+1);
    Serial.println(present[p]);
    delay(3000);
  }
  }*/
  /*if(present[0] == LOW and previous[0] == HIGH){  //籃框
    Serial.println(i);
    if(i == 0)*/
    
  if(present[0] == LOW and previous[0] == HIGH){
    i = 1;
    in = 1;
  }
  if(present[0] == HIGH and previous[0] == LOW){
    i = 0;
    in = 0;
  }
  if(i == 1)//按鈕按下(開始) 馬達正轉
    pos1 = 180;
  if(i == 0){ //按鈕離開停止
    pos1 = 90;
    
  }
  if(digitalRead(sw_PIN_board_RIGHT) == LOW and in == 1){      //碰到右側微動 馬達反轉
    //Serial.println(3);
    pos1 = 180;
    
            
    }            
  if(digitalRead(sw_PIN_board_LEFT) == LOW and in ==1){       //碰到左側微動 馬達正轉
    //Serial.println(4);
    pos1 = 0;
    i = 2;
    
    }
  
    
  //if(present[1] == LOW and previous[1] == HIGH){//手臂程式
  if(present[1] == LOW and previous[1] == HIGH){
    j = 1;
    in1 = 1;
  }
  if(present[1] == HIGH and previous[1] == LOW){
    j = 0;
    in1 = 0;
  }
      
  
  if(j == 1) //按鈕按下開始
    pos2 = 180;
  if(j == 0) //按鈕按下停止
    pos2 = 90;
  if(digitalRead(sw_PIN_hand_FRONT)== LOW and in1 == 1){  //碰到前微動 馬達反轉
    //Serial.println(2);
    pos2 = 0;
    j = 2;
  }
  if(digitalRead(sw_PIN_hand_BACK)== LOW and in1 == 1){ //碰到後微動 馬達正轉
    //Serial.println(3);
    pos2 = 180;
    
  }
  /*if(present[2] == LOW and previous[2] == HIGH){
    if(l == 0)
      l = 1;
    else
      l = 0;
  }
  if(l == LOW)
    ascentservo.write(180);
  if(l == HIGH)
    ascentservo.write(90);*/
  boardservo.write(pos1);
  handservo.write(pos2);
  previous[0] = present[0];
  previous[1] = present[1];
  
  Serial.println(in);
  //Serial.println(present[0]);
  //Serial.println(previous[0]);
  }    
  
