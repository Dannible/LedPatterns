/*
 *  Created: November 26, 2015
 *  By: Dan Ward <dpw989@gmail.com>
 *
 *  Push a button to cycle between 3 patterns.
 */

const int buttonPin = 13; //Button Pin
const long IntervalRealLong = 2000; //wait 2 seconds.
const long IntervalLong = 1000; //wait 1 seconds.
const long IntervalMedium = 500; //wait .5 seconds.
const long IntervalShort = 250; //wait .25 seconds.
const long IntervalRealShort = 125; //wait .12 seconds.
const boolean DEBUG = false; // Set Debugging.

//Array, holds list of LED pins.
int LedPins[] = {
  7, 8, 9};

//Button States, start LOW.
int ButtonState = LOW;
int LastButtonState = LOW;

//Array, Holds list of LED states. Init to all LOW. 
int LedState[] = {
  LOW, LOW, LOW};

//Current time, Updates at beginning of loop. 
unsigned long currentTime = 0;

//Array, Holds list of the last time a LED state was changed. 
unsigned long LastLedTime[] = {
  0,0,0};

//Changed when LED pattern is incremented. 
int SelectedPattern = 0;

//Array, Holds the timings for the selected pattern.
long Pattern[3];

/*
* Init the pins and start serial 
 */
void setup() {

  pinMode(LedPins[0], OUTPUT);
  pinMode(LedPins[1], OUTPUT);
  pinMode(LedPins[2], OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  loadPatternDefault();

  if(DEBUG)
    Serial.begin(9600);
    
    
}

/*
* Main Loop, Check button states and timing for each LED. 
 */
void loop() {
  currentTime = millis(); //NOW
  ButtonState = digitalRead(buttonPin); //check button state.

  if(LastButtonState != ButtonState) //if button state has changed.
    if(ButtonState == LOW) //If button is LOW.
      IncrementPattern(); //Increment the Pattern by 1.

  LastButtonState = ButtonState; // update button state.

  for(int i =0; i < 3; i++) //Loop each LED and check the last time it's state was changed. 
  {
    //Take the difference of the current time and the last time the state was changed.
    //If the difference is grater then the value stored in the selected pattern, change it's state. 
    if(currentTime - LastLedTime[i] >= Pattern[i]) 
    {
      LastLedTime[i] = millis();//log the time.
      ToggleLed(i);//change LED state.
    }  
  }
}

