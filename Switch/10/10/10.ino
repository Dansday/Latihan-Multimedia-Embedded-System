/*
* MONSTER ARDUINO V2
* Program 5 Tombol 5 LED
* www.ElangSakti.com
*/
// led setting active high
#define LED_ON HIGH
#define LED_OFF !LED_ON
// definisikan 5 tombol
#define TOMBOL_NONE 0
#define TOMBOL1 1
#define TOMBOL2 2
#define TOMBOL3 3
#define TOMBOL4 4
#define TOMBOL5 5
// output tombol di pin A0
// pin led di pin 2 - 6
const byte PIN_TOMBOL = A0;
const byte PIN_LED[] = {2,3,4,5,6};
// nilai data tombol sesuai tabel
// dan nilai toleransi 15
const int TOMBOL_VAL[] = {204,255,341,511,1023};
const byte TOLERANSI = 15;
// status led untuk lock status
byte STATUS_LED[] = {LED_OFF,LED_OFF,LED_OFF,LED_OFF,LED_OFF};
// tombol dalam array
const byte TOMBOL[] = {
TOMBOL1, TOMBOL2, TOMBOL3,
TOMBOL4, TOMBOL5 };
// tombol saat ini dan tombol sebelumnya
byte tombol = 0;
byte tombol_last = 0;
// data saat ini dan data sebelumnya
int data = 0;
int data_last = 0;
// delay untuk penekanan tombol
unsigned long delay_press = 400; // dalam ms
unsigned long delay_press_last = 0;
void setup() {
// buka koneksi ke serial
Serial.begin(19200);
while(!Serial);
// tombol sebagai input
pinMode(PIN_TOMBOL,INPUT);
// pin sebagai output, defaultnya OFF
for(byte i=0; i<sizeof(PIN_LED); i++){
pinMode(PIN_LED[i],OUTPUT);
digitalWrite(PIN_LED[i],LED_OFF);
}
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
// baca data analog tombol
data = analogRead(PIN_TOMBOL);
// reset tombol sebelumnya
tombol = TOMBOL_NONE;
// cocokkan data dengan ke-5 data tombol
for(byte i=0; i<sizeof(TOMBOL); i++){
// hitung koreksi data tombol
// jika ada yang cocok,
// catat tombol yang sesuai, lalu
// hentikan looping.
if( abs(data - TOMBOL_VAL[i]) < TOLERANSI ){
tombol = TOMBOL[i];
break;
}
}
// jika ada tombol yang cocok
// cetak tombol, panggil aksi tombol
// lalu catat waktu pembacaan tombol
if(tombol != TOMBOL_NONE){
Serial.println(tombol);
AksiTombol(tombol);
tombol_last = tombol;
delay_press_last = millis();
}
}
}
// fungsi AksiTombol
// INPUT : byte tombol
void AksiTombol(byte tombol){
// konversi dari nomer tombol menjadi index tombol
byte index_led = tombol-1;
// balik status LED sesuai index/led yang cocok
// jika HIGH, ubah jadi LOW, dan sebaliknya
STATUS_LED[index_led] = !STATUS_LED[index_led];
// cetak sesuai tombol yang terpilih
switch(tombol){
case TOMBOL1:
// proses sesuatu
if( STATUS_LED[index_led] == LED_ON ){
Serial.println("Nyalakan LED 1");
} else {
Serial.println("Matikan LED 1");
}
break;
case TOMBOL2:
// proses sesuatu
if( STATUS_LED[index_led] == LED_ON ){
Serial.println("Nyalakan LED 2");
} else {
Serial.println("Matikan LED 2");
}
break;
case TOMBOL3:
// proses sesuatu
if( STATUS_LED[index_led] == LED_ON ){
Serial.println("Nyalakan LED 3");
} else {
Serial.println("Matikan LED 3");
}
break;
case TOMBOL4:
// proses sesuatu
if( STATUS_LED[index_led] == LED_ON ){
Serial.println("Nyalakan LED 4");
} else {
Serial.println("Matikan LED 4");
}
break;
case TOMBOL5:
// proses sesuatu
if( STATUS_LED[index_led] == LED_ON ){
Serial.println("Nyalakan LED 5");
} else {
Serial.println("Matikan LED 5");
}
break;
}
// hidup matikan led, sesuai status led
digitalWrite(PIN_LED[index_led],STATUS_LED[index_led]);
}
