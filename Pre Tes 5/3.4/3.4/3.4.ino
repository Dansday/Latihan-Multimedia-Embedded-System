const int pinPot = A0;
const int pinLED = 9;
void setup() {
pinMode(pinPot, INPUT);
pinMode(pinLED, OUTPUT);
}
int sensor = 0;
void loop() {
// baca nilai kaki A0 (sensor, potensiometer)
sensor = analogRead(pinPot);
// durasi kedipan sesuai nilai pada sensor 0-1023
digitalWrite(pinLED, HIGH);
delay(sensor);
digitalWrite(pinLED, LOW);
delay(sensor);
}
