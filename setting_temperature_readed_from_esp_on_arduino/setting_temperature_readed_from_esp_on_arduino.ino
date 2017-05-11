#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int T;            //temperature in Fahrenheit
int logs = 0;     //this variable is ONLY for to get the temperature direction
char data[4];
int pos = 0; 

const int ledFullCool = 8;
const int ledCool = 9;
const int ledReHeat = 10;
const int ledHeat = 11;

void setup() {
  pinMode(ledFullCool, OUTPUT);
  pinMode(ledCool, OUTPUT);
  pinMode(ledReHeat, OUTPUT);
  pinMode(ledHeat, OUTPUT);
  
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Starting...");
}

void loop()
{
  if (mySerial.available() > 0) {
    while (mySerial.available() > 0) {
        data[pos++] = mySerial.read();
    }
  }

  Serial.print(data);
  
  pos = 0;

//  Serial.println(result);
//  result = "";

  //====FullCool====
  // if(T<=75)
  //   digitalWrite(ledFullCool, LOW);
  // else
  //   digitalWrite(ledFullCool, HIGH);

  // //====Heat====
  // if(T>=70)
  //   digitalWrite(ledHeat, LOW);
  // else
  //   digitalWrite(ledHeat, HIGH);

  // if(logs < T) {  //====from COOL to HOT====
  //   //====ReHeat====
  //   if(T>=74)
  //     digitalWrite(ledReHeat, LOW);
  //   else
  //     digitalWrite(ledReHeat, HIGH);

  //   //====Cool====
  //   if(T<73)
  //     digitalWrite(ledCool, LOW);
  //   else
  //     digitalWrite(ledCool, HIGH);
  // }
  // else if(logs > T) {  //====from HOT to COOL====
  //   //====ReHeat====
  //   if(T>73)
  //     digitalWrite(ledReHeat, LOW);
  //   else
  //     digitalWrite(ledReHeat, HIGH);

  //   //====Cool====
  //   if(T<=71)
  //     digitalWrite(ledCool, LOW);
  //   else
  //     digitalWrite(ledCool, HIGH);
  // }
  
  // logs = T;
  
  // Serial.println(T);
  delay(1000);
  
}
