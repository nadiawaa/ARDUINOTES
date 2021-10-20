void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  int turbidity = map(sensorValue, 650,940, 100, 0); //Mapping sensor, 650 nilai terkecil, 940 nilai terbesar, 100 dan 0 untuk mapping dan mengubah nilai dari 0-100
  Serial.println(turbidity); // print out the value you read:
  delay(500);
}
