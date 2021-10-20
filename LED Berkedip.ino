//program untuk menyalakan LED dan mematikan LED dengan delay 2 detik

int ledA=12;  //D12
int ledB=11;  //D11
int ledC=10;  //D10

void setup(){
 pinMode(ledA, OUTPUT);
 pinMode(ledB, OUTPUT);
 pinMode(ledC, OUTPUT);
}
void loop(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledC, HIGH);
 delay(2000);  //delay 2 detik
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
 delay(2000);
}
