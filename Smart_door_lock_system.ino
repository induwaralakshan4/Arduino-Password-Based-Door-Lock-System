#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_AIP31068_I2C.h>
#include <Keypad.h>


Servo motor;

byte row[4]={2,3,4,5};
byte col[3]={6,7,8};

char keys[4][3]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','='}
};

Keypad mys = Keypad(makeKeymap(keys), row, col, 4, 3);
LiquidCrystal_AIP31068_I2C lcd(0x3E, 25, 2);

long inputdata=0;


void setup() {
  Serial.begin(9600); 
  Serial.println("Uno is Ready");
  lcd.init();          
  lcd.setCursor(0, 0); 
  lcd.print(" ...Welcome...");
  lcd.setCursor(0, 1); 
  lcd.print("(Enter Password)");
  motor.attach(31);
  pinMode(13,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);

  
       
}

void loop() {
  motor.write(0);
  
 char Key = mys.getKey();

  if (Key != NO_KEY) {
    // Buzzer
    digitalWrite(13,HIGH);
    delay(20);
    digitalWrite(13,LOW);

    lcd.init();          
    lcd.setCursor(0, 0);
    if (Key >= '0' && Key <= '9'){
      inputdata=(inputdata*10)+(Key-'0');
      lcd.print("-Enter Password-");
      lcd.setCursor(0, 1); 
      lcd.print(inputdata);
    }
    else if(Key=='='){
      lcd.print("Verifying...");
      if (inputdata==456){
        lcd.init();          
        lcd.setCursor(0, 0); 
        lcd.print("Password is correct !");
        lcd.setCursor(0, 1); 
        lcd.print("Door was unlocked...");
        digitalWrite(23,HIGH);
        motor.write(0);
        motor.write(180);
        delay(5000);
        digitalWrite(23,LOW);
        inputdata=0;

      }
      else{
        lcd.init();          
        lcd.setCursor(0, 0); 
        lcd.print("Password incorrect !");
        lcd.setCursor(0, 1); 
        lcd.print("Try again...");
        digitalWrite(22,HIGH);
        digitalWrite(13,HIGH);
        delay(100);
        digitalWrite(22,LOW);
        digitalWrite(22,HIGH);
        inputdata=0;
        delay(1000);
        digitalWrite(13,LOW);
        digitalWrite(22,LOW);
        
      }
    }
    else{
      inputdata=0;
      lcd.print("Cleared!");
    }
  }

}