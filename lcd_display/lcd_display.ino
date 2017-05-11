#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial mySerial(2, 3); //Rx | Tx

void setup()
{
  // initialize the LCD
  lcd.init();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Welcome to ATI");
  mySerial.begin(9600);
}

void loop()
{
   // when characters arrive over the serial port...
   if (mySerial.available() > 0) {
     // wait a bit for the entire message to arrive
     delay(100);
     // clear the screen
     lcd.clear();
     // read all the available characters
     while (mySerial.available() > 0) {
         lcd.write(mySerial.read());
     }
   }
}
