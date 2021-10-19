int ledA=12;
int ledB=11;
int ledC=10;

void setup(){
 pinMode(ledA, OUTPUT);
 pinMode(ledB, OUTPUT);
 pinMode(ledC, OUTPUT);
}
void loop(){
   digitalWrite(ledA, HIGH);
   digitalWrite(ledB, HIGH);
   digitalWrite(ledC, HIGH);
   delay(2000);
   digitalWrite(ledA, LOW);
   digitalWrite(ledB, LOW);
   digitalWrite(ledC, LOW);
}
