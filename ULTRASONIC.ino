#include <NewPing.h>  
//library yang baru saja di install dengan cara diatas  
//pin arduino yang digunakan  
#define trigPin 3 
#define echoPin 4 
// Tentukan jarak maksimum yang ingin kita ping (dalam sentimeter). Jarak sensor maksimum adalah 400-500 cm 
#define MAX_DISTANCE 250
NewPing sonar = NewPing(trigPin, echoPin, MAX_DISTANCE);  
void setup() {  
//Baut komunikasi yang disettingkan di serial monitor 
Serial.begin(9600); 
} 
void loop() { 
delay(500);  
Serial.print("Jarak Pembacaan = "); 
Serial.print(sonar.ping_cm()); //nilai jarak yang terbaca 
Serial.println(" cm");  
//contoh pengondisian menggunakan IF, jika jarak terdeteksi pada jarak samadengan 300cm dan lebih dari itu maka led built in akan blinking  
//iki sg bener
} 
