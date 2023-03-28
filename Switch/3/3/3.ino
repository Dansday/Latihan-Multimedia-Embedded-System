/*
* MONSTER ARDUINO V2
* Program Tombol yang Manusiawi
* www.ElangSakti.com
*/
// kita set supaya tombol active low
#define ON LOW
#define OFF !ON
// tombol pada pin 2
const byte PIN_TOMBOL = 2;
// data awal ada OFF
// dan data sebelumnya juga OFF
boolean data = OFF;
boolean data_last = data;
void setup() {
// buka koneksi ke serial
Serial.begin(19200);
while(!Serial);
// tombol sebagai input dengan pullup resistor
pinMode(PIN_TOMBOL,INPUT_PULLUP);
}
void loop() {
// baca data tombol
data = digitalRead(PIN_TOMBOL);
// jika data berbeda dari data sebelumnya
// cetak ke serial monitor
if(data != data_last){
  // jika ON, cetak ON
// jika OFF, cetak OFF
if(data == ON){
Serial.println("ON");
} else {
Serial.println("OFF");
}
// simpan data sebagai data sebelumnya
data_last = data;
}
}
