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

//Temperatura variables
int logs;
int Temp;
//============================

//DEFINE ALL FUNCTIONS HERE
int get_current_temp();
void get_references(int T);
void set_lcd(int value);

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
  lcd.print("Welcome to SIM");
  delay(2000);

  //Initialize the SerialPort for
  //to send the data to ESP Module
  Serial.begin(9600);
}

void loop()
{
  switchSimulatorState = digitalRead(switchSimulatorPin);
  if(switchSimulatorState != ACTIVATED)
  {
    //Update temperature in the LCD
    set_lcd(Temp);
    
    //Turn ON the Simulator LED
    digitalWrite(ledSimulatorPin, HIGH);

    //Read the Up and Down states
    btnUpState = digitalRead(btnUpPin);
    btnDownState = digitalRead(btnDownPin);

    //increse or decreser the Temp. value
    if(btnUpState == ACTIVATED) { Temp++; }
    if(btnDownState == ACTIVATED) { Temp--; }   
  }
  else
  {
    //read the temperature sensor
    Temp = get_current_temp();

    //Turn OFF the Simulator LED
    digitalWrite(ledSimulatorPin, LOW);

    //Update temperature in the LCD
    set_lcd(Temp); 
  }

  //send the Temp. to the function
  //for to put the references
  get_references(Temp);
  
  //"Send" the temperature value to
  //server ESP Module
  Serial.print(Temp);
   
  delay(100);
}
