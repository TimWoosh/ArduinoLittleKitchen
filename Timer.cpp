#include "Timer.h"
#include <Arduino.h>

Timer::Timer():
  seconds(0),
  countingDown(false),
  done(false)
{
}

long Timer::getMsSinceStart()
{
  return this->msStart - millis();
}

int Timer::getSecSinceStart()
{
  return round((millis() - this->msStart) / 1000);
}

int Timer::getSec()
{
  return this->seconds;
}

int Timer::getSecLeft()
{
  
  return this->seconds - getSecSinceStart();
}

void Timer::start()
{
  Serial.println("timer started with " + String(this->seconds) + " seconds");
  this->countingDown = true;
  this->msStart = millis();
}

void Timer::pause()
{
  this->countingDown = false;
}

void Timer::reset()
{
  this->seconds = 0;
  this->countingDown = false;
}

void Timer::setSec(int seconds)
{
  this->seconds = seconds;
}

void Timer::addSec(int seconds)
{
  this->seconds = this->seconds + seconds;  
}

bool Timer::isDone()
{
  return done;
}

void Timer::update()
{
  if(this->countingDown && this->getSecLeft() <= 0)
  {
    this->done = true;
    this->countingDown = false;
    this->msStart = 0;
    this->seconds = 0;
  }
  
  if(millis() - this->msLast > 1000)
  {
    Serial.println(String(this->getSecLeft()) + " seconds left");
    this->msLast = millis();
  }
}

