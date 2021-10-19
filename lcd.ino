//Buat program untuk memunculkan tulisan di LCD dengan aturan :
//➢ Ketika tombol 1 ditekan tulisan akan muncul di baris pertama LCD : tombol 1 ditekan
//➢ Ketika tombol 2 ditekan tulisan akan muncul di baris pertama LCD : tombol 2 ditekan
//➢ Fungsi lcd.clear(); untuk menghapus semua tulisan yang ada di LCD Tambahkan didalam 
//program sehingga ketika tombol 3 ditekan tuliasan akan hilang.



#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int tb1=10;
int tb2=9;
int tb3=8;

void setup() {
 lcd.begin(16, 2);
 lcd.print("hello, world!");
 pinMode(tb1, INPUT);
 pinMode(tb2, INPUT);
 pinMode(tb3, INPUT);
 }
void loop() {
 if(digitalRead(tb1)==LOW){
   for (int positionCounter = 0; positionCounter < 40; positionCounter++){
     lcd.scrollDisplayRight();
     delay(150);
   }
 }
 if(digitalRead(tb2)==LOW){
   for (int positionCounter = 0; positionCounter < 40; positionCounter++){
     lcd.scrollDisplayLeft();
     delay(150);
   }
 }
}
