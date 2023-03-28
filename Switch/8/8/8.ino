/*
* MONSTER ARDUINO V2
* Program Analisis Output Tombol
* www.ElangSakti.com
*/
// output tombol di pin A0
const byte PIN_TOMBOL = A0;
// data saat ini dan data sebelumnya
int data = 0;
int data_last = 0;
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
// tombol sebagai input
pinMode(PIN_TOMBOL,INPUT);
}
void loop() {
// panggil fungsi utk membaca tombol
TombolListener();
}
void TombolListener(){
// jika selisih waktu penekanan tombol
// lebih besar dari waktu delay tombol
// baca tombol lagi, jika tidak tombol tdk dibaca
if( millis() - delay_press_last > delay_press ){
// baca data tombol
data = analogRead(PIN_TOMBOL);
// jika data lebih kecil dari 10 abaikan
if( data < 10 ) return;
// jika data berbeda dari data sebelumnya
// cetak ke serial monitor
if(data != data_last){
Serial.println(data);
data_last = data;
delay_press_last = millis();
}
}
}
