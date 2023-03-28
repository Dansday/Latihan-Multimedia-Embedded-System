/*
* MONSTER ARDUINO V2
* Program Satu Tombol Banyak Menu
* www.ElangSakti.com
*/
// kita set supaya tombol active low
#define ON LOW // active low
#define OFF !ON
// definisikan 4 buah menu
// menu 0 - 3
#define MENU_0 0
#define MENU_1 1
#define MENU_2 2
#define MENU_3 3
// tombol pada pin 2
const byte PIN_TOMBOL = 2;
// data awal ada OFF
// dan data sebelumnya juga OFF
boolean data = OFF;
boolean data_last = data;
// variabel untuk lock status
boolean logika = data;
// jadikan menu sebagai array supaya lebih mudah
const byte MENU[] = {MENU_0,MENU_1,MENU_2,MENU_3};
// siapkan teks nama-nama menu
const String TEKS_MENU[] = {
"Menu Utama",
"Menu 1 Setting",
"Menu 2 Input Data",
"Menu 3 Exit"
};
// cata menu yang aktif saat ini
// saat start, menu yg aktif adalah menu_3
byte MENU_COUNTER = MENU_3;
// delay untuk penekanan tombol.
// setelah tombol ditekan, maka selama 150 ms
// tidak bisa ditekan.
// delay ini berguna untuk menghindari 2 kali eksekusi
unsigned long delay_press = 150; // dalam ms
unsigned long delay_press_last = 0;
void setup() {
// buka koneksi ke serial
Serial.begin(19200);
while(!Serial);
// tombol sebagai input dengan pullup resistor
pinMode(PIN_TOMBOL,INPUT_PULLUP);
}
void loop() {
// baca logika tombol
TombolListener();
}
// fungsi TombolListener
void TombolListener(){
// jika selisih waktu penekanan tombol
// lebih besar dari waktu delay tombol
// baca tombol lagi, jika tidak tombol tdk dibaca
if( millis() - delay_press_last > delay_press ){
// baca data tombol
data = digitalRead(PIN_TOMBOL);
// jika data berbeda dari data sebelumnya
// cetak ke serial monitor
if(data != data_last){
// jika data = ON
if(data == ON){
// pilih menu selanjutnya
MENU_COUNTER++;
// jika menu melebihi jumlah menu yg ada
// pilih menu awal
if( MENU_COUNTER >= sizeof(MENU) ){
MENU_COUNTER = 0;
}
// eksekusi aksi tombol sesuai logika
AksiTombol(MENU_COUNTER);
}
// simpan data sebagai data sebelumnya
data_last = data;
// catat waktu penekanan tombol terakhir
delay_press_last = millis();
}
}
}
// Fungsi AksiTombol
// INPUT : byte tombol
void AksiTombol(byte tombol){
// print sesuai menu yang dipilih
switch(tombol){
case MENU_0:
// proses sesuatu
Serial.println(TEKS_MENU[MENU_0]);
break;
case MENU_1:
// proses sesuatu
Serial.println(TEKS_MENU[MENU_1]);
break;
case MENU_2:
// proses sesuatu
Serial.println(TEKS_MENU[MENU_2]);
break;
case MENU_3:
// proses sesuatu
Serial.println(TEKS_MENU[MENU_3]);
break;
}
}
