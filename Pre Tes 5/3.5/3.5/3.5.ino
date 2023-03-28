const int pinPot = A0;
const int pinLED = 9;
void setup() {
pinMode(pinPot, INPUT);
pinMode(pinLED, OUTPUT);
}
long lastTime = 0;
int sensor = 0;
int ledValue;
void loop() {
// baca nilai kaki A0 (sensor, potensiometer)
sensor = analogRead(pinPot);
// led akan hidup/mati dengan durasi = nilai sensor
// jika nilai sensor 100 maka durasinya adalah 100ms
if(millis() > lastTime + sensor){
if(ledValue == LOW){
ledValue = HIGH;
}else{
ledValue = LOW;
}
// set lastTime dg nilai millis() yang baru
lastTime = millis();
digitalWrite(pinLED, ledValue);
}
}
