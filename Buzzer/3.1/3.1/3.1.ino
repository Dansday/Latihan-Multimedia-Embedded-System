#define BUZZER_ON LOW
#define BUZZER_OFF !BUZZER_ON
const byte PIN_BUZZER = 2;
void setup() {
// pin buzzer sebagai output
pinMode(PIN_BUZZER, OUTPUT);
}
void loop() {
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
}
