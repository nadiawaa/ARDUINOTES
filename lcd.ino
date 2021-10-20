//Buat program untuk memunculkan tulisan di LCD dengan aturan :
//➢ Ketika tombol 1 ditekan tulisan akan running kanan : tombol 1 ditekan
//➢ Ketika tombol 2 ditekan tulisan akan running kiri : tombol 2 ditekan
//➢ Fungsi lcd.clear(); untuk menghapus semua tulisan yang ada di LCD Tambahkan didalam 

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tb1=10; //D10
int tb2=9;  //D9

void setup() {
 lcd.begin(16, 2);
 lcd.print("hello, world!");
 pinMode(tb1, INPUT);
 pinMode(tb2, INPUT);

 }
void loop() {
 if(digitalRead(tb1)==LOW){
   for (int positionCounter = 0; positionCounter < 40; positionCounter++){
     lcd.scrollDisplayRight(); //running kanan
     delay(150);
   }
 }
 if(digitalRead(tb2)==LOW){
   for (int positionCounter = 0; positionCounter < 40; positionCounter++){
     lcd.scrollDisplayLeft(); //running kiri
     delay(150);
   }
 }
}
