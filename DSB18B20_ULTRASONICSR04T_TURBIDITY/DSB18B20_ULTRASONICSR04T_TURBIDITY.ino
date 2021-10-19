#include <OneWire.h> //adc
#include <DallasTemperature.h> //DS18B20 sensor suhu
#include <NewPing.h> //SR04T sensor ultrasonic

#define ONE_WIRE_BUS 2 //Suhu D2
#define trigPin 3 //Ultrasonic Trig D3
#define echoPin 4 //Ultrasonic Echo D4
#define MAX_DISTANCE 400 //Jarak maks Ultrasonic
NewPing sonar = NewPing(trigPin, echoPin, MAX_DISTANCE);
OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire device    
DallasTemperature sensors(&oneWire); // Pass oneWire reference to DallasTemperature library

void setup(){
  sensors.begin();
  Serial.begin(9600); 
}

void loop(){
  
//Turbidity
  int sensorValue = analogRead(A0);
  int turbidity = map(sensorValue, 650,940, 100, 0);
    Serial.print("Tubidity     : ");
    Serial.println(turbidity);
  delay(50);

//Temperature
  sensors.requestTemperatures();   
    Serial.print("Temperature  : ");  
    Serial.print(sensors.getTempCByIndex(0)); 
    Serial.println(" C"); 
  delay(50); 

//Ultrasonic
  int jarak = sonar.ping_cm();
    Serial.print("Jarak        : ");
    Serial.print(jarak);
    Serial.println("cm");
  delay(50);

 Serial.println("----------------------------");
 delay(5000);

} 
