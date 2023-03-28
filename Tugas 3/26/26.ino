const int pinLED1 = 8;
const int pinLED2 = 9;
const int pinLED3 = 10;
const int pinLED4 = 11;

void setup() {
pinMode(pinLED1, OUTPUT);
pinMode(pinLED2, OUTPUT);
pinMode(pinLED3, OUTPUT);
pinMode(pinLED4, OUTPUT);
}

void loop() {
digitalWrite(pinLED1, LOW);
digitalWrite(pinLED2, LOW);
digitalWrite(pinLED3, LOW);
digitalWrite(pinLED4, LOW);
delay(1000);
digitalWrite(pinLED1, HIGH);
delay(1000);
digitalWrite(pinLED2, HIGH);
delay(1000);
digitalWrite(pinLED3, HIGH);
delay(1000);
digitalWrite(pinLED4, HIGH);
delay(1000);
}
