int pinApi = 10;
int pinAlarm = 11;
int redLED = 13;
int data;
void setup()
{
pinMode(pinApi, INPUT);
pinMode(pinAlarm, OUTPUT);
pinMode(redLED, OUTPUT);
}
void loop()
{
data = digitalRead(pinApi);
if (data == LOW)
{
digitalWrite(pinAlarm, HIGH);
digitalWrite(redLED, HIGH);
delay(5000);
}
else
{
digitalWrite(redLED, LOW);
digitalWrite(pinAlarm, LOW);
delay(1000);
}
}
