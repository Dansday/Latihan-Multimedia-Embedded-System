//Inisialisasi
#define trigPin 11
#define echoPin 10
void setup(){
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop(){
int duration, distance;
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance =(duration/2)/29.1;
Serial.print("Jarak Objek = ");
Serial.println(distance);
Serial.print(" cm");
delay(1000);
}
