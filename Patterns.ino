void IncrementPattern()
{
  SelectedPattern++;
  if(SelectedPattern>3)
    SelectedPattern = 0;

  switch(SelectedPattern)
  {
  case 0:
    loadPattern1();
    break;
  case 1:
    loadPattern2();
    break;
  case 2:
    loadPattern3();
    break;
  }

  Serial.print("Selected Pattern");
  Serial.print(SelectedPattern);
  Serial.println(".");
}


void loadPattern1()
{
  Pattern[0]= IntervalLong;
  Pattern[1]= IntervalShort;
  Pattern[2]= IntervalRealShort;
}

void loadPattern2()
{
  Pattern[0]= IntervalMedium;
  Pattern[1]= IntervalShort;
  Pattern[2]= IntervalLong;
}

void loadPattern3()
{
  Pattern[0]= IntervalShort;
  Pattern[1]= IntervalLong;
  Pattern[2]= IntervalRealLong;
}

