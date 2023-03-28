int ledDelay = 5000; 
int redPin = 11;
int yellowPin = 12; 
int greenPin = 13;

void setup() {
pinMode(redPin, OUTPUT);
pinMode(yellowPin, OUTPUT); 
pinMode(greenPin, OUTPUT);
}

void loop() {
digitalWrite(redPin, HIGH);
digitalWrite(yellowPin, LOW);
delay(ledDelay);

digitalWrite(yellowPin, HIGH);
digitalWrite(redPin, LOW); 
delay(2000);

digitalWrite(greenPin, HIGH);
digitalWrite(yellowPin, LOW);
delay(ledDelay);

digitalWrite(yellowPin, HIGH);
digitalWrite(greenPin, LOW); 
delay(2000);
}
