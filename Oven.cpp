//Oven.cpp

#include "Oven.h"
#include "ArduinoExt.h"
#include <Arduino.h>
#include <Bounce2.h>


Oven::Oven(int pinBtnPwr, int pinLedPwr, int pinLedOven, int pinBtnAdd1, int pinBtnAdd10, int pinBtnReset, int pinLedDone)
:	PIN_BTN_PWR(pinBtnPwr),
	PIN_LED_PWR(pinLedPwr),
	PIN_LED_OVEN(pinLedOven),
  PIN_BTN_ADD_1(pinBtnAdd1),
  PIN_BTN_ADD_10(pinBtnAdd10),
  PIN_BTN_RESET(pinBtnReset),
  PIN_LED_DONE(pinLedDone),
  hot(false),
  on(false)
{
  pinMode(this->PIN_BTN_PWR, INPUT);
  pinMode(this->PIN_BTN_ADD_1, INPUT);
  pinMode(this->PIN_BTN_ADD_10, INPUT);
  pinMode(this->PIN_BTN_RESET, INPUT);
  pinMode(this->PIN_LED_PWR, OUTPUT);
  pinMode(this->PIN_LED_OVEN, OUTPUT);
	
	this->on = false;
	this->hot = false;

  this->mTimer = Timer();
  
	this->debouncerOn = Bounce();
	this->debouncerOn.attach(this->PIN_BTN_PWR);
	this->debouncerOn.interval(5);
  
  this->add1Sec = Bounce();
  this->add1Sec.attach(this->PIN_BTN_ADD_1);
  this->add1Sec.interval(5);
  
  this->add10Sec = Bounce();
  this->add10Sec.attach(this->PIN_BTN_ADD_10);
  this->add10Sec.interval(5);
  
  this->reset = Bounce();
  this->reset.attach(this->PIN_BTN_RESET);
  this->reset.interval(5);
}

void Oven::update()
{
  //Handle On/Off Button and LED
	this->debouncerOn.update();
	bool risen = this->debouncerOn.rose();
	if(risen)
	{
		this->isOn() ? this->switchOff() : this->switchOn(); //Toggle Oven On/Off
	}

  //Handle Done Led and Timer

  this->mTimer.update();
  if(this->mTimer.isDone()){
    Serial.println("Cake is ready!");
  }
  digitalWrite(this->PIN_LED_DONE, boolToPinState(this->mTimer.isDone())); //TODO: make function for this
}

void Oven::switchOn()
{
  Serial.println("Oven on");
	this->on = true;
	digitalWrite(this->PIN_LED_PWR, boolToPinState(true));
}

void Oven::switchOff()
{
  Serial.println("Oven off");
	this->on = false;
  this->mTimer.reset();
	digitalWrite(this->PIN_LED_PWR, boolToPinState(false));
}

bool Oven::isOn()
{
	return this->on;
}

bool Oven::isHot()
{
	return this->hot;
}

void Oven::pushAdd1Sec()
{
  this->mTimer.addSec(1);
}

void Oven::pushAdd10Sec()
{
  Serial.println("adding 10 seconds to baking time");
  this->mTimer.addSec(10);
}

void Oven::start()
{
  Serial.println("Starting baking");
	this->hot = true;
  this->mTimer.start();
}


