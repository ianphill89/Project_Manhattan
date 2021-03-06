int T;            //temperature in Fahrenheit
int logs = 0;     //this variable is ONLY for to get the temperature direction

const int ledFullCool = 8;
const int ledCool = 9;
const int ledReHeat = 10;
const int ledHeat = 11;

pinMode(ledFullCool, OUTPUT);
pinMode(ledCool, OUTPUT);
pinMode(ledReHeat, OUTPUT);
pinMode(ledHeat, OUTPUT);

void get_references() {
  error = Sensor1.getTSicTemp(&temperature);  //turn the TSIC-Sensor ON -> messure -> OFF
  temp=temperature/100.0;                     //convert to Celsius
  T=round((temp*1.8)+32);                     //convert to Fahrenheit

  //====FullCool====
  if(T<=75)
    digitalWrite(ledFullCool, LOW);
  else
    digitalWrite(ledFullCool, HIGH);

  //====Heat====
  if(T>=70)
    digitalWrite(ledHeat, LOW);
  else
    digitalWrite(ledHeat, HIGH);

  if(logs < T) {  //====from COOL to HOT====
    //====ReHeat====
    if(T>=74)
      digitalWrite(ledReHeat, LOW);
    else
      digitalWrite(ledReHeat, HIGH);

    //====Cool====
    if(T<73)
      digitalWrite(ledCool, LOW);
    else
      digitalWrite(ledCool, HIGH);
  }
  else if(logs > T) {  //====from HOT to COOL====
    //====ReHeat====
    if(T>73)
      digitalWrite(ledReHeat, LOW);
    else
      digitalWrite(ledReHeat, HIGH);

    //====Cool====
    if(T<=71)
      digitalWrite(ledCool, LOW);
    else
      digitalWrite(ledCool, HIGH);
  }
  
  logs = T;

  Serial.print(T);
  
  delay(1000);
  
}
