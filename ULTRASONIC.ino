#include <NewPing.h>  //library yang harus diinstall  
#define trigPin 3 //pin D3
#define echoPin 4 //pin D4
#define MAX_DISTANCE 250 //Jarak maksimum (maks 400-500 cm)
NewPing sonar = NewPing(trigPin, echoPin, MAX_DISTANCE);

void setup() {  
Serial.begin(9600); 
} 

void loop() { 
delay(500);  
Serial.print("Jarak Pembacaan = "); 
Serial.print(sonar.ping_cm()); //nilai jarak yang terbaca 
Serial.println(" cm");  
} 
