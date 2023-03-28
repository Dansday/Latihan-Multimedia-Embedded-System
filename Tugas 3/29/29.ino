const int numLED = 4;
const int pinLED[numLED] = {8,9,10,11};

void setup() {
for(int i=0; i<4; i++){
pinMode(pinLED[i], OUTPUT);
 }
}

void loop() {
  
for(int i=0; i<3; i++){
digitalWrite(pinLED[i], HIGH);
delay(200);
digitalWrite(pinLED[i], LOW);
 }
 
for(int i=3; i>0; i--){
digitalWrite(pinLED[i], HIGH);
delay(200);
digitalWrite(pinLED[i], LOW);
 }
}
