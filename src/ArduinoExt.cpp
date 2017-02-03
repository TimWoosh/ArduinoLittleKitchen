#include <Arduino.h>

int boolToPinState(bool state)
{
  return state ? HIGH : LOW;
}
