#include <TSIC506.h>  //temperatura library

//Temperature Pins Statement
TSIC506 Sensor1(5, 4);  //(VCC, DATA)
int error;        //1 = OK, 0 = parity error    return value of getTSicTemp()
int temperature;  // "return" of temperature in degrees Celsius * 100
float temp;       // temperature in degrees Celsius

int get_current_temp() {
  error = Sensor1.getTSicTemp(&temperature);  //turn the TSIC-Sensor ON -> messure -> OFF
  temp=temperature/100.0;                     //convert to Celsius
  return round((temp*1.8)+32);                //convert to Fahrenheit  
}
