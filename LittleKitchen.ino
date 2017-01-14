/*
 * Little Kitchen v.0.1
 * Author: T. Wöstemeier
 * Changed date: 30-Dec-2016
 */

#include <Bounce2.h>
#include <Arduino.h>
#include "Oven.h"
#include "ArduinoExt.h"

/*************************
 * Input pins
 *************************/
int PIN_BTN_ON_OFF = 24;
int PIN_BTN_ADD_1 = 30;
int PIN_BTN_ADD_10 = 31;
int PIN_BTN_RESET = 32;

/*************************
 * Output pins
 *************************/
int PIN_LED_ON_OFF = 22;
int PIN_LED_OVEN = 28;
int PIN_LED_DONE = 33;

/**************************
 * Variables
 **************************/
boolean stateOnOff = false; 
int time = 0;


Oven oven = Oven(PIN_BTN_ON_OFF, 
                  PIN_LED_ON_OFF, 
                  PIN_LED_OVEN,
                  PIN_BTN_ADD_1,
                  PIN_BTN_ADD_10,
                  PIN_BTN_RESET,
                  PIN_LED_DONE);
Bounce debouncerOnOff = Bounce();



/***************
 **** SETUP ****
 ***************/
void setup() {
//  // put your setup code here, to run once:
//  /*************************
//  * Input pins
//  *************************/
//  pinMode(PIN_BTN_ON_OFF, INPUT);
//  
//  /*************************
//   * Output pins
//   *************************/
//  pinMode(PIN_LED_ON_OFF, OUTPUT);
//
//
//  /*************************
//   * Other
//   *************************/
//  debouncerOnOff.attach(PIN_BTN_ON_OFF);
//  debouncerOnOff.interval(5);
  
  //digitalWrite(PIN_BTN_ON_OFF, stateOnOff);

  Serial.begin(9600);
  oven.pushAdd10Sec();
  oven.start();
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
//  debouncerOnOff.update();
//  int OnOffReadout = debouncerOnOff.read();
//  boolean OnOffRose = debouncerOnOff.rose();

  

  /************************
   * Process inputs
   ************************/
  if(millis() != time)
  {
    oven.update();
    time = millis();
  }



  /************************
   * Write ouputs
   ************************/

  /*
   * On/Off actions
   */
//  digitalWrite(PIN_LED_ON_OFF, boolToOutput(stateOnOff)); //Set On/Off LED
}



