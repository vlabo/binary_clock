#include "FastLED.h"
#include "Time.h"

#define NUM_LEDS 6

#define SECONDS_PIN 6
#define MINUTES_PIN 7
#define HOURS_PIN 8

// Define the array of leds
CRGB secondsArray[NUM_LEDS];
CRGB minutesArray[NUM_LEDS];
CRGB hoursArray[NUM_LEDS];

void setup() 
{ 
  FastLED.addLeds<UCS1903, SECONDS_PIN, RGB>(secondsArray, NUM_LEDS);
  FastLED.addLeds<UCS1903, MINUTES_PIN, RGB>(minutesArray, NUM_LEDS);
  FastLED.addLeds<UCS1903, HOURS_PIN, RGB>(hoursArray, NUM_LEDS);

  setTime( 14, 34, 12, 1, 1, 1999 ); //(hr,min,sec,day,month,yr);
  //Serial.begin( 38400 );
}

void fillArrayWithNumber( CRGB* array, int number, CRGB color = CRGB::Red )
{
    for(int i = 0; i < NUM_LEDS; i++ )
      array[i] = ( (number >> i) & 0x00000001 ) == 1 ? color : CRGB::Black;
}

void loop() 
{

  fillArrayWithNumber( secondsArray, second(), CRGB::Red);
  fillArrayWithNumber( minutesArray, minute(), CRGB::Blue );
  fillArrayWithNumber( hoursArray, hour(), CRGB::Green );
  
  FastLED.show();
  delay(100);

}
