#define sc 4
void setup() {
  pinMode(sc,INPUT_PULLUP);

}
int present_sc = HIGH, previous_sc = HIGH; 
int score = 0;
void loop() {
  present_sc = digitalRead(sc);

  if(present_sc == LOW and previous_sc == HIGH){ 
    Serial.println(score);
    delay(500);
    score = score+1;
  }
  previous_sc = present_sc;
}
