#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int soilMoistureValue = 0;
int percentage=0;
int relaypin=D4;

void setup() {

  pinMode(3,OUTPUT);

  Serial.begin(9600);
   lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(percentage); 
  lcd.print("  ");
}

void loop() {
   Wire.begin(D2, D1);
  lcd.init();
  lcd.backlight();
  pinMode(D4, OUTPUT);
  //digitalWrite(D4, HIGH);
  lcd.setCursor(0, 0);
  lcd.println("IrrigationSystem");
  lcd.setCursor(0,1);
  lcd.print("percentage :");
  lcd.print(percentage); 
 

soilMoistureValue = analogRead(A0);

Serial.println(percentage);

percentage = map(soilMoistureValue, 490, 1023, 100, 0);

if(percentage < 10)  

{

  Serial.println(" pump on");
  lcd.println("on");
  digitalWrite(D4,HIGH);
  

}

if(percentage >80)

{

  Serial.println("pump off");
    lcd.println("off");
  digitalWrite(D4,LOW);

}

}
