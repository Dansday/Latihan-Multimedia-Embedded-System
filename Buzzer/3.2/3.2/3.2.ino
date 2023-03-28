#define BUZZER_ON LOW
#define BUZZER_OFF !BUZZER_ON
// GND buzzer dihubungkan ke pin 2
const byte PIN_BUZZER = 2;
// variabel untuk cek waktu kirim
unsigned long waktu_kirim = 0;
void setup() {
// aktifkan komunikasi serial
// pada baudrate 19200
Serial.begin(19200);
// tunggu hinga Serial siap digunakan
while(!Serial);
// pin buzzer sebagai output
pinMode(PIN_BUZZER, OUTPUT);
// pastikan buzzer maat saat pertama kali start
digitalWrite(PIN_BUZZER, BUZZER_OFF);
// catat waktu kirim pertama kali
waktu_kirim = millis();
}
void loop() {
// kirim data
KirimData();
// bunyi tilit tilit
TilitTilit();
}
void TilitTilit(){
// Tit pertama
digitalWrite(PIN_BUZZER, BUZZER_ON);
delay(200);
// mati sebentar
digitalWrite(PIN_BUZZER, BUZZER_OFF);
delay(100);
// Tit kedua
digitalWrite(PIN_BUZZER, BUZZER_ON);
delay(200);
// mati agak lama
digitalWrite(PIN_BUZZER, BUZZER_OFF);
delay(1000);
// tambahan delay supaya pas 3 detik :v
delay(1500);
}
// fungsi untuk mengirim data
void KirimData(){
// cetak selisih waktu kirim sebelumnya
// dengan pengiriman saat ini
Serial.print("Selisih Waktu : ");
Serial.println( millis() - waktu_kirim );
// catat waktu kirim data
waktu_kirim = millis();
}
