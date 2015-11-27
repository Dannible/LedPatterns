/*
* Toggle LED 1
*/
void ToggleLed1()
{
  if(LedState[0] == LOW)
    LedState[0] = HIGH;
  else
    LedState[0]=LOW;
    
  digitalWrite(LedPins[0], LedState[0]);
  LedToggleOut(LedPins[0], LedState[0]);
}

/*
* Toggle LED 2
*/
void ToggleLed2()
{
  if(LedState[1] == LOW)
    LedState[1] = HIGH;
  else
    LedState[1]=LOW;
    
  digitalWrite(LedPins[1], LedState[1]);
  LedToggleOut(LedPins[1], LedState[1]);
}

/*
* Toggle LED 3
*/
void ToggleLed3()
{
  if(LedState[2] == LOW)
    LedState[2] = HIGH;
  else
    LedState[2]=LOW;
    
  digitalWrite(LedPins[2], LedState[2]);
  LedToggleOut(LedPins[2], LedState[2]);
}

/*
* Toggle LED
*
* int led = position of LED to toggle.
*/
void ToggleLed(int led)
{
  if(LedState[led] == LOW)
    LedState[led] = HIGH;
  else
    LedState[led]=LOW;
    
  digitalWrite(LedPins[led], LedState[led]);
  LedToggleOut(LedPins[led], LedState[led]);
}

/*
* Output Debugging for LED Change. 
*
* int led = Position of LED
* int state = State of LED. 
*/
void LedToggleOut(int led, int state)
{
  if(DEBUG)
  {
      Serial.print("LED ");
      Serial.print(led);
      Serial.print(" Has been Toggled ");
      Serial.println( (state == HIGH) ? "HIGH" : "LOW" );
      delay(10);
  }
}
