#include <Wire.h> //mengaktifkan komunikasi i2c
#include <LiquidCrystal_I2C.h> //mengaktifkan komunikasi lcd menjadi i2c
//Sensor Ultrasonik = su
const int sutrig = 2; //trigger ultrasonik ke pin 3
const int suecho = 3; //echo ultrasonik ke pin 2
//Sensor Tanah = st
const int stpin = A0; //sensor tanah ke analog 0
const int pompa = 13
; //pompa ke pin 4
long durasi; //deklarasi durasi tipe data long
int jarak; //deklarasi jarak tipe data integer

LiquidCrystal_I2C lcd(0x27, 16, 2); //tipe lcd 0x27(biru) dengan 16 x 2 titik

void setup() {
  lcd.begin(); //memulai lcd
  lcd.setCursor(2,0); //posisi teks
  lcd.print("Danto"); //membuat teks
  lcd.setCursor(8,0); //posisi teks
  lcd.print("&"); //membuat teks
  lcd.setCursor(10,0); //posisi teks
  lcd.print("Anoo"); //membuat teks
  lcd.setCursor(3,1); //posisi teks
  lcd.print("Projek UAS"); //membuat teks
  delay (3000); //membuat delay
  pinMode(sutrig, OUTPUT); //deklarasi output
  pinMode(suecho, INPUT); //deklarasi input
  pinMode(stpin, INPUT); //deklarasi input
  pinMode(pompa, OUTPUT); //deklarasi output
}

void loop() {
  int kelembapan = analogRead (stpin); //membaca data dari sensor tanah
  digitalWrite(sutrig, LOW); //trigger ultrasonik mati
  delayMicroseconds(2); //membuat delay
  digitalWrite(sutrig, HIGH); //trigger ultrasonik nyala
  delayMicroseconds(10); //membuat delay
  digitalWrite(sutrig, LOW); //trigger ultrasonik mati
  durasi = pulseIn(suecho, HIGH); //membaca data dari sensor ultrasonik
  jarak = durasi*0.034/2; //mengubah data dari sensor ultrasonik menjadi cm
  
  if (jarak < 1) { //jarak dibawah 5cm
    lcd.setCursor(0,0); //posisi teks
    lcd.print("Volume Air:100%     "); //membuat teks
    }

   else if (jarak < 3) { //jarak dibawah 10cm
    lcd.setCursor(0,0); //posisi teks
    lcd.print("Volume Air:75%     "); //membuat teks
    }
    
   else if (jarak < 4 ) { //jarak dibawah 15cm
    lcd.setCursor(0,0); //posisi teks
    lcd.print("Volume Air:50%     "); //membuat teks
    }

   else if (jarak < 6) { //jarak dibawah 20cm
    lcd.setCursor(0,0); //posisi teks
    lcd.print("Volume Air:25%     "); //membuat teks
    }    
    
   else { //jarak diatas 20cm
    lcd.setCursor(0,0); //posisi teks
    lcd.print("Volume Air:Habis     "); //membuat teks
    }
    
  if (kelembapan < 600) { //nilai sensor tanah dibawah 600
    lcd.setCursor(0,1); //posisi teks
    lcd.print("Tanah Basah     "); //membuat teks
    digitalWrite (pompa, HIGH); //pompa mati
    }
    
   else { //nilai sensor tanah diatas 600
    lcd.setCursor(0,1); //posisi teks
    lcd.println("Tanah Kering     "); //membuat teks
    digitalWrite (pompa, LOW); //pompa nyala
  }
  
  delay (500); //membuat delay
  
}
