void get_references(int T) {
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
}
