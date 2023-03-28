//Inisialisasi
#define trigPin 11
#define echoPin 10
int duration, distance;
int greenLED = 13;
int redLED = 9;

void setup()
{
Serial.begin(9600);
pinMode(greenLED, OUTPUT);
pinMode(redLED, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  duration = pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;

  if (echoPin == LOW)
  {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    Serial.print("Jarak Objek = ");
    Serial.println(distance);
    Serial.print("cm");
    delay(1000);
  }
}
