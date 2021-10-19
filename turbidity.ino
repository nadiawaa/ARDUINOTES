
void setup() {
  Serial.begin(9600); //Baud rate: 9600
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  int turbidity = map(sensorValue, 650,940, 100, 0);
  Serial.println(turbidity); // print out the value you read:
  delay(500);
}
