void ToggleLed1()
{
  if(LedState[0] == LOW)
    LedState[0] = HIGH;
  else
    LedState[0]=LOW;
    
  digitalWrite(LedPins[0], LedState[0]);
}

void ToggleLed2()
{
  if(LedState[1] == LOW)
    LedState[1] = HIGH;
  else
    LedState[1]=LOW;
    
  digitalWrite(LedPins[1], LedState[1]);
}

void ToggleLed3()
{
  if(LedState[2] == LOW)
    LedState[2] = HIGH;
  else
    LedState[2]=LOW;
    
  digitalWrite(LedPins[2], LedState[2]);
}

void ToggleLed(int led)
{
  if(LedState[led] == LOW)
    LedState[led] = HIGH;
  else
    LedState[led]=LOW;
    
  digitalWrite(LedPins[led], LedState[led]);
}
