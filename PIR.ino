#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensor = 7;
int red_led = 12;
int sensorstate = 0;
int green_led=13;
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
    lcd.print("Umuntu");
    lcd.setCursor(0,1);
    lcd.print("aciyeho");
    digitalWrite(buzzer, HIGH);
    delay(1000);
    lcd.clear();
    }


    
  else{
    digitalWrite(green_led, HIGH);
    digitalWrite(red_led, LOW);
    lcd.print("ntamuntu");
    lcd.setCursor(0, 1);
    lcd.print("uciyeho");
    digitalWrite(buzzer, 0);
    delay(1000);
    lcd.clear();
    }  
}
