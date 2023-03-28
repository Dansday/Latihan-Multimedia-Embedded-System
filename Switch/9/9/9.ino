/*
* MONSTER ARDUINO V2
* Program Menu 5 Tombol
* www.ElangSakti.com
*/
// definisikan 5 tombol
#define TOMBOL_NONE 0
#define TOMBOL1 1
#define TOMBOL2 2
#define TOMBOL3 3
#define TOMBOL4 4
#define TOMBOL5 5
// output tombol di pin A0
const byte PIN_TOMBOL = A0;
// nilai data tombol sesuai tabel
const int TOMBOL_VAL[] = {204,255,341,511,1023};
// nilai koreksi
const byte KOREKSI = 15;
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
if( abs(data - TOMBOL_VAL[i]) < KOREKSI ){
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
switch(tombol){
case TOMBOL1:
// proses sesuatu
Serial.println("Menu 1");
break;
case TOMBOL2:
// proses sesuatu
Serial.println("Menu 2");
break;
case TOMBOL3:
// proses sesuatu
Serial.println("Menu 3");
break;
case TOMBOL4:
// proses sesuatu
Serial.println("Menu 4");
break;
case TOMBOL5:
// proses sesuatu
Serial.println("Menu 5");
break;
}
}
