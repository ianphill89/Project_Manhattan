void set_lcd(int value) {
  lcd.clear();
  lcd.print("Temp. = ");
  lcd.print(value);
  lcd.print((char)223);
  lcd.print("F");
}
