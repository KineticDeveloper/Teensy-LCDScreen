//connect to which analog pin
#define BATTERY_VOLTAGE A2
//how may samples to take in 
#define NUM_SAMPLES 10

#include <TFT.h> // Arduino LCD lib
#include <SPI.h>

//pin definition for mega

#define cs 10
#define dc 9
#define rst 8

TFT TFTscreen = TFT(cs, dc, rst); 

//char array to print to screen 
//char sensorPrintout[4];

int samples[NUM_SAMPLES];

void setup() {
  Serial.begin(9600); 
  analogReference(EXTERNAL); 
  TFTscreen.begin();
  TFTscreen.background(0,0,0); // clear LCD screen
  TFTscreen.stroke(255, 255, 255); // set background LCD screen white 
  TFTscreen.setTextSize(2); //set font size
  TFTscreen.text("Sensor Value :/n" , 0,0); //types this in top left corner of lcd screen 
  TFTscreen.setTextSize(5); //set font large for the loop

}

void loop(void) {
 uint8_t i; //type def for unsigned char 
 float average; 

 //take N samples in a row, with small delay 
 for (i = 0; i < NUM_SAMPLES; ++i) { 
   samples[i] = analogRead(BATTERY_VOLTAGE); 
   delay(10); 
 }

 //average the samples
 for (i = 0; i < NUM_SAMPLES; ++i) { 
  average += samples[i]; 
 }
 average /= NUM_SAMPLES;

  Serial.print("Average analog reading "); 
  Serial.println(average);

  delay(1000); 

  String sensorVal = String(analogRead(A2));

  //set font color
  int redRandom = random (0,255); 
  int greenRandom = random (0, 255); 
  int blueRandom = random (0, 255);

  TFTscreen.stroke (redRandom, greenRandom, blueRandom);
  TFTscreen.write(sensorVal, 0, 20);
  delay(250)
  TFTScreen.stroke(0,0,0); 
  TFTScreen.write (sensorVal, 0, 20);
  }
