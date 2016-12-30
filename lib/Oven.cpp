//Oven.cpp

#include "Oven.h"
#include "ArduinoExt.h"
#include <Arduino.h>
#include <Bounce2.h>


Oven::Oven(int pinBtnPwr, int pinLedPwr, int pinLedOven)
:	PIN_BTN_PWR(pinBtnPwr),
	PIN_LED_PWR(pinLedPwr),
	PIN_LED_OVEN(pinLedOven)
{
	pinMode(this->PIN_BTN_PWR, INPUT);
	pinMode(this->PIN_LED_PWR, OUTPUT);
	
	this->on = false;
	this->hot = false;
	
	this->debouncerOn = Bounce();
	this->debouncerOn.attach(this->PIN_BTN_PWR);
	this->debouncerOn.interval(5);
}

void Oven::update()
{
	this->debouncerOn.update();
	bool risen = this->rose();
	if(risen)
	{
		this->isOn() : this->switchOff() : this->switchOn(); //Toggle On/Off
		digitalWrite(this->PIN_LED_PWR, boolToOutput(this->isOn()));
	}
}

void Oven::switchOn()
{
	this->on = true;
}

void Oven::switchOff()
{
	this->on = false;
}

bool Oven::isOn()
{
	return this->on;
}

bool Oven::isHot()
{
	return this->hot;
}

bool Oven::isCountingDown()
{
	
}

int Oven::getTimerSec()
{
	
}

void Oven::setTimerSec(int seconds)
{
	
}

void Oven::start()
{
	
}

