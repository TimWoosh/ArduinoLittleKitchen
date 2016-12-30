/*
 * Little Kitchen v.0.1
 * Author: T. Wöstemeier
 * Changed date: 30-Dec-2016
 */

#include <Bounce2.h>
#include <Arduino.h>
#include "lib\Oven.h"

/*************************
 * Input pins
 *************************/
int PIN_BTN_ON_OFF = 24;

/*************************
 * Output pins
 *************************/
int PIN_LED_ON_OFF = 22;

/**************************
 * Variables
 **************************/
boolean stateOnOff = false; 
int time = 0;


Bounce debouncerOnOff = Bounce();



/***************
 **** SETUP ****
 ***************/
void setup() {
  // put your setup code here, to run once:
  /*************************
  * Input pins
  *************************/
  pinMode(PIN_BTN_ON_OFF, INPUT);
  
  /*************************
   * Output pins
   *************************/
  pinMode(PIN_LED_ON_OFF, OUTPUT);


  /*************************
   * Other
   *************************/
  debouncerOnOff.attach(PIN_BTN_ON_OFF);
  debouncerOnOff.interval(5);
  
  //digitalWrite(PIN_BTN_ON_OFF, stateOnOff);

  Serial.begin(9600);
}


/***************
 **** LOOP *****
 ***************/
void loop() {

  /************************
   * Read inputs
   ************************/
   /*
    * On/Off button
    */
  debouncerOnOff.update();
  int OnOffReadout = debouncerOnOff.read();
  boolean OnOffRose = debouncerOnOff.rose();

  

  /************************
   * Process inputs
   ************************/
  if(millis() != time)
  {
    if(OnOffRose){ stateOnOff = !stateOnOff; }
    
    time = millis();
  }



  /************************
   * Write ouputs
   ************************/

  /*
   * On/Off actions
   */
  digitalWrite(PIN_LED_ON_OFF, stateOnOff ? HIGH : LOW); //Set On/Off LED
}



