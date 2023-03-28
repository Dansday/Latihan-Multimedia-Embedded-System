//Inisialisasi pin
int ledPin = 13;
int inputPin = A0;
int pirState = LOW;
int val = 0;
void setup()
{
pinMode(ledPin, OUTPUT);
pinMode(inputPin, INPUT);
Serial.begin(9600);
}
void loop()
{
val = digitalRead(inputPin);
if (val == HIGH)
{
digitalWrite(ledPin, HIGH);
if (pirState == HIGH) {
Serial.println("Gerakan Terdeteksi!");
pirState = LOW;
}
}
else
{
digitalWrite(ledPin, LOW);
if (pirState == LOW){
Serial.println("Tidak Ada Gerakan!");
pirState = HIGH;
}
}
}
