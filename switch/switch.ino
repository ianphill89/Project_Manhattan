#define ACTIVATED LOW //Esto es para no tener que usar un external resistor 

//Simulator button and LED setting
const int switchPin = 3;
int switchState = 0;
const int ledPin = 13;

void setup()
{
  Serial.begin(115200);
  
  //initializing the Simulator pins
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  switchState = digitalRead(switchPin);
  if(switchState != ACTIVATED) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
