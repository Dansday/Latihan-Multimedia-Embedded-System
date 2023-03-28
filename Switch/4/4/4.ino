/*
* MONSTER ARDUINO V2
* Program Tombol dengan Lock Status
* www.ElangSakti.com
*/
// kita set supaya tombol active low
#define ON LOW // active low
#define OFF !ON
// tombol pada pin 2
const byte PIN_TOMBOL = 2;
// data awal ada OFF
// dan data sebelumnya juga OFF
boolean data = OFF;
boolean data_last = data;
// variabel untuk lock status
boolean logika = data;
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
// balik status logika tolbol
logika = !logika;
// jika ON, cetak ON
// jika OFF, cetak OFF
if( logika == ON ){
Serial.println("ON");
} else {
  Serial.println("OFF");
}
}
// simpan data sebagai data sebelumnya
data_last = data;
// catat waktu penekanan tombol terakhir
delay_press_last = millis();
}
}
}
