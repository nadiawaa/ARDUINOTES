//Monitoring Suhu, Kelembaban, Pakan Kandang Anak Ayam dengan sesor suhu (DHT11) dan ultrasoonic(HS04)

#include <ESP8266WiFi.h> //Library NodeMCU
#include <FirebaseArduino.h>  //library firebase
#include <NewPing.h> //library hc-sr04
#include <Servo.h> //library servo
#include "DHT.h" // library dht11

#define DHTPIN D7  //DHT pada pin D7
DHT dht(DHTPIN,DHT11);
#define echoPin D5  //ultrasonic pin D5
#define trigPin D6  //ultrasonic pin D6
#define MAX_DISTANCE 250 //max jarak(cm)
NewPing sonar(D5, D6, 250); //setup pin hcsr04 dan jarak pembacaan dengan fungsi library
#define servoPin D3  //Servo pin D3
Servo myservo;
#define FIREBASE_HOST "host firebase" //host Firebase
#define FIREBASE_AUTH "auth firebase" //Auth firebase
#define WIFI_SSID "ssid" //SSID wifi
#define WIFI_PASSWORD "pwd" //Password Wifi


String pilih;     //setting
String kondisi;   //manual
String katup;      //jam


void setup() {
  Serial.begin(9600);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  pinMode (trigPin, OUTPUT);            //ultrasonic
  pinMode (echoPin, INPUT);             //ultrasonic
  pinMode (D8, OUTPUT);                 //relay
  myservo.attach(servoPin);             //servo
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();
}
int n = 0;


void loop() {

  
//DHT11(Suhu kelembaban)_________________________________________________________________
  float hi=1, low=0;
  float h = dht.readHumidity();
  Firebase.setFloat("Coop/Kelembaban", h);
  float t = dht.readTemperature();
  Firebase.setFloat("Coop/Suhu", t);

//==============================================================================
  pilih = Firebase.getString("Coop/setting");
  Serial.print("setting : ");
  Serial.println(pilih);
 
  if(pilih=="1"){  //mode otomatis
   Serial.print("Kelembaban : ");
   Serial.print(h);
   Serial.println("% ");
   Serial.print("Suhu : ");
   Serial.print(t);
   Serial.println("C  ");

    if (t<=31){  //jika suhu kurang dari 31, lammpu menyala
      digitalWrite(D8, LOW);
      Firebase.setFloat("Coop/Lampu",hi);
      Serial.println("Lampu On");
    }
    if (t>31){    //jika suhu lebih dari 31, lampu mati
      digitalWrite(D8, HIGH);
      Firebase.setFloat("Coop/Lampu",low);
      Serial.println("Lampu Off");
    }
   
  }
  
  if(pilih=="0"){ //mode manual
   kondisi = Firebase.getString("Coop/Relay");
   Serial.print("Relay: ");
   Serial.println(Firebase.getString("Coop/Relay"));
  
    if(kondisi=="1"){  //relay on, lampu menyala
      digitalWrite(D8, LOW);
      Serial.println("Lampu On");
      Firebase.setFloat("Coop/Lampu",hi);
    }
    if(kondisi=="0"){  //relay off, lampu mati
      digitalWrite(D8, HIGH);
      Serial.println("Lampu Off");
      Firebase.setFloat("Coop/Lampu",low);
    }
    
  } 

//ultrasonic__________________________________________________________________________________________________
  int jarak = sonar.ping_cm(); //pembacaan jarak dalam cm
  Firebase.setFloat("Coop/Ultrasonic", jarak);
  Serial.print("Jarak : ");
  Serial.print(jarak);
  Serial.println(" cm");

  

//servo____________________________________________________________________________________________________________
  katup = Firebase.getString("Coop/katup");
  
  if(katup == "1"){ //jika sudah waktunya
    if(jarak>5){  //jika jarak lebih dari 5, servo terbuka
      myservo.write(90);
      delay(1000);
      myservo.write(90);
      delay(1000);
      myservo.write(-90);
      Firebase.setFloat("Coop/Servo",hi);
      Serial.println  ("Servo Terbuka"); 
      delay(1000);
    }
  
    else{   //jika jarak lkurang dari 5, servo tertutup
      Serial.println("Servo Tertutup");
      Firebase.setFloat("Coop/Servo",low);
    }
  }    
    else{  //jika belum waktunya
      Serial.println("Servo Tertutup");
      Firebase.setFloat("Coop/Servo",low);
    }
  
  Serial.println("=====================================");
    delay(1000);  
    if (Firebase.failed()){
    Serial.print("pushing/logs failed: ");
    Serial.println(Firebase.error());
    }
     return;
  }
