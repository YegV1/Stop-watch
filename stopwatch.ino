#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
long msOffset=0;
int Sec=0;
int Min=0;
int Hr=0;
int Days=0;
bool Held=0;
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  pinMode(10,OUTPUT);
  msOffset=millis(); 
}

void loop() {
  analogWrite(10,64);
  lcd.home();
  lcd.print(String(Days)+":"+String(Hr)+":"+String(Min)+":"+String(Sec)+":"+String(millis()-msOffset)+"  ");
  if(millis()-msOffset>1000){
    msOffset+=1000;
    Sec++;
  }
  if(Sec>=60){
    Sec=0;
    Min++;
  }
  if(Min>=60){
    Min=0;
    Hr++;
  }
  if(Hr>=24){
    Hr=0;
    Days++;
  }
  if(analogRead(0)<900&!analogRead(0)<700&!Held){
    Held=1;
    lcd.setCursor(0,1);
    lcd.print(String(Days)+":"+String(Hr)+":"+String(Min)+":"+String(Sec)+":"+String(millis()-msOffset)+" ");
  }
  if(!(analogRead(0)<900&!analogRead(0)<700&Held)){
    Held=0;
  }
}
