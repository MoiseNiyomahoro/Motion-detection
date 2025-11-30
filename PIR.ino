#include <LiquidCrystal.h>
LiquidCrystal_I2C lcd(12,11,5,4,3,2);
int sensor = 7;
int red_led = 13;
int green_led=6;
int buzzer = 8;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  lcd.backlight();
}

void loop() {
  sensorstate = digitalRead(sensor);
  if(sensorstate == HIGH){
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    lcd.setCursor(0,0);
    lcd.print("motion ");
    lcd.setCursor(0,1);
    lcd.print("detected");
    digitalWrite(buzzer, HIGH);
    delay(1000);
    lcd.clear();
    }


    
  else{
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    lcd.print("no motion");
    lcd.setCursor(0, 1);
    lcd.print("detected");
    digitalWrite(buzzer, 0);
    delay(1000);
    lcd.clear();
    }  
}
