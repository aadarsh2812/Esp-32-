
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
const int trigpin = 32;
const int echopin = 35;
LiquidCrystal_I2C lcd(0x27, 16, 2);

long duration;
int distance;


void setup() 
  {
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
    Wire.begin();  
    Serial.begin(9600); 
    lcd.begin();
	lcd.backlight();
  
  }

void loop() 
{


  
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  lcd.print(distance);
  delay(500);
  lcd.clear();
}

