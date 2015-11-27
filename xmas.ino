/*
 *  Dan Ward
 *
 *
 */

const int buttonPin = 13;
const long IntervalRealLong = 2000;
const long IntervalLong = 1000;
const long IntervalMedium = 500;
const long IntervalShort = 250;
const long IntervalRealShort = 125;

int LedPins[] = {
  7, 8, 9};

int ButtonState = LOW;
int LastButtonState = LOW;

int LedState[] = {
  LOW, LOW, LOW};

unsigned long currentTime = 0;
unsigned long LastLedTime[] = {
  0,0,0};

int SelectedPattern = 0;

long Pattern[3];

void setup() {

  pinMode(LedPins[0], OUTPUT);
  pinMode(LedPins[1], OUTPUT);
  pinMode(LedPins[2], OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  currentTime = millis();
  ButtonState = digitalRead(buttonPin);

  if(LastButtonState != ButtonState)
    if(ButtonState == LOW)
      IncrementPattern();

  LastButtonState = ButtonState;

  for(int i =0; i < 3; i++)
  {
    if(currentTime - LastLedTime[i] >= Pattern[i])
    {
      LastLedTime[i] = millis();
      ToggleLed(i);
    }  
  }
}






