#define ACTIVATED LOW //Esto es para no tener que usar un external resistor 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Down button setting
const int btnDownPin = 6;
int btnDownState = 0;

//Up button setting
const int btnUpPin = 7;
int btnUpState = 0;

//Simulator button and LED setting
const int switchSimulatorPin = 3;
int switchSimulatorState = 0;
const int ledSimulatorPin = 13;

//======GLOBAL VARIABLES======
//References LED setting
const int ledFullCool = 8;
const int ledCool = 9;
const int ledReHeat = 10;
const int ledHeat = 11;

int logs;
int Temp;
//============================

//DEFINE ALL FUNCTIONS HERE
int get_current_temp();
void get_references(int T);

void setup()
{
  //initializing the Up pins
  pinMode(btnUpPin, INPUT);
  digitalWrite(btnUpPin, HIGH);
  
  //initializing the Down pins
  pinMode(btnDownPin, INPUT);
  digitalWrite(btnDownPin, HIGH);
  
  //initializing the Simulator pins
  pinMode(switchSimulatorPin, INPUT);
  digitalWrite(switchSimulatorPin, HIGH);
  pinMode(ledSimulatorPin, OUTPUT);

  //initializing the References pins
  pinMode(ledFullCool, OUTPUT);
  pinMode(ledCool, OUTPUT);
  pinMode(ledReHeat, OUTPUT);
  pinMode(ledHeat, OUTPUT);

  //initializing logs variable
  logs = Temp = get_current_temp();
  
  // initialize the LCD
  lcd.init();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Simulator v1");
  delay(2000);
}

void loop()
{
  switchSimulatorState = digitalRead(switchSimulatorPin);
  if(switchSimulatorState != ACTIVATED) {
    lcd.clear();
    lcd.print("Temp. = ");
    lcd.print(Temp);
    lcd.print((char)223);
    lcd.print("F");

    digitalWrite(ledSimulatorPin, HIGH);
    btnUpState = digitalRead(btnUpPin);
    btnDownState = digitalRead(btnDownPin);

    if(btnUpState == ACTIVATED) { Temp++; }
    if(btnDownState == ACTIVATED) { Temp--; }

    get_references(Temp);    
  }
  else {
    Temp = get_current_temp();
    digitalWrite(ledSimulatorPin, LOW);

    lcd.clear();
    lcd.print("Temp. = ");
    lcd.print(Temp);
    lcd.print((char)223);
    lcd.print("F");

    get_references(Temp); 
  }

  delay(100);
}
