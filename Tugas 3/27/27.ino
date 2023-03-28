const int numLED = 4;
const int pinLED[numLED] = {8,9,10,11};

void setup() {
for(int i=0; i<4; i++){
pinMode(pinLED[i], OUTPUT);
 }
}

void loop() {

for(int i=0; i<4; i++){
digitalWrite(pinLED[i], LOW);
}

delay(1000);
 
for(int i=0; i<4; i++){
digitalWrite(pinLED[i], HIGH);
delay(1000);
 }
}
