#include <LiquidCrystal.h>

#define TRIGGER 10
#define ECHO 9
#define BUZINA 7
#define LEDVERDE 6
#define LEDVERMELHO 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("TRENA DIGITAL");

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZINA,OUTPUT);
  pinMode( LEDVERDE , OUTPUT);
  pinMode( LEDVERMELHO , OUTPUT)
}

void loop() {
  lcd.setCursor(0, 1);
  float cmMsec;

  digitalWrite(TRIGGER,LOW);
  delayMicroseconds(5);  
  digitalWrite(TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER,LOW);
  float duracao = pulseIn(ECHO,HIGH);
 
  if (cmMsec < 15){
    tone(BUZINA,300);
    digitalWrite(LEDVERDE,LOW);
    digitalWrite(LEDVERMELHO,HIGH);
    
  }
    
  else{ 
    noTone(BUZINA);
    digitalWrite(LEDVERDE,HIGH);
    digitalWrite(LEDVERMELHO,LOW);
    
  }

  lcd.print(cmMsec);
  delay(500);
}