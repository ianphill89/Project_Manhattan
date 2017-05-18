//Cuando se va a enviar datos a travez del puerto serie
//entre dos boards estos tienen que tener un GND comun
//esto es muy importante sin esto no funciona, entre
//boards arduino con un solo cable es suficiente
//from Tx to Rx

char data[4] = {0}; //este array de 4 posiciones cubre T>=100
int pos = 0;
boolean flag = false;

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  //Serial.println("if");
  if (Serial.available() > 0) { //si connecto 
    //Serial.println(" while");
    //mientras reciba data hago tal cosa
    while(Serial.available() > 0) { 
      char c = Serial.read();
//      if(c == '\n') {
//        Serial.print("-");
//      }else if(c != '\n' && isDigit(c)) {
//        Serial.print(c);
//        Serial.print("*");
//      }
        //Serial.print("the character is: ");
        //Serial.println(c);
        if(c != '\n' && isDigit(c)) {
          //Serial.print(c);
          //Serial.print("*");
          data[pos++] = c;
          flag = true;
        }
        else {
          //Serial.print("-");          
          break;
        }
    }
    //Serial.println(" endwhile");
  }
  //Serial.println("endif");
  
  if(flag){
    Serial.println(data);
    data[pos] = '\0';
    pos = 0;
    flag = false;
  }
  

  //no puede ser mas de 1s pq se pierden pktes
  delay(1000);
}
