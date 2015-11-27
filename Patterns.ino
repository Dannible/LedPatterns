/*
* Increment and set the newly selected Pattern.
 */
void IncrementPattern()
{
  SelectedPattern++; //Increment the selected pattern
  if(SelectedPattern>3) //If the Pattern is greater than 3, set it back to 0.
    SelectedPattern = 0;

  if(DEBUG) //IF debugging
  {
    Serial.print("Selected Pattern: ");
    Serial.print(SelectedPattern);
    Serial.println("."); 
  }

  switch(SelectedPattern)
  {
  case 0:
    loadPattern1(); //Set Pattern 1.
    break;
  case 1:
    loadPattern2(); //Set Pattern 2.
    break;
  case 2:
    loadPattern3(); //Set Pattern 3.
    break;
  }
}

/*
* Set Default Pattern 
*/
void loadPatternDefault()
{
  Pattern[0]= IntervalShort;
  Pattern[1]= IntervalMedium;
  Pattern[2]= IntervalLong;
  PatternDebugOut();
}

/*
* Set Pattern 1 
*/
void loadPattern1()
{
  Pattern[0]= IntervalLong;
  Pattern[1]= IntervalShort;
  Pattern[2]= IntervalRealShort;
  PatternDebugOut();
}

/*
* Set Pattern 2
*/
void loadPattern2()
{
  Pattern[0]= IntervalMedium;
  Pattern[1]= IntervalShort;
  Pattern[2]= IntervalLong;
  PatternDebugOut();
}

/*
* Set Pattern 3
*/
void loadPattern3()
{
  Pattern[0]= IntervalShort;
  Pattern[1]= IntervalLong;
  Pattern[2]= IntervalRealLong;
  PatternDebugOut();
}

/*
* Out put pattern to serial. 
*/
void PatternDebugOut()
{
  if(DEBUG)
  {
    Serial.print("Pattern: ");
    Serial.print(Pattern[0]);
    Serial.print(", ");
    Serial.print(Pattern[1]);
    Serial.print(", ");
    Serial.println(Pattern[3]);
    delay(10);  
  } 
}




