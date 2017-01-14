//Oven.h

#ifndef LK_OVEN
#define	LK_OVEN

#include <Bounce2.h>
#include "Timer.h"

class Oven
{
	public:
		Oven(int pinBtnPwr, int pinLedPwr, int pinLedOven, int pinBtnAdd1, int pinBtnAdd10, int pinBtnReset, int pinLedDone);
		void update();
		void switchOn();
		void switchOff();
		bool isOn();
    void pushAdd1Sec();
    void pushAdd10Sec();
		bool isHot();
    void start();

	private:
		int     PIN_BTN_PWR,
		        PIN_BTN_ADD_1,
		        PIN_BTN_ADD_10,
		        PIN_BTN_RESET, 
            PIN_LED_PWR, 
            PIN_LED_OVEN,
            PIN_LED_DONE;
		bool    on, hot;
		Bounce  debouncerOn;
    Bounce  add1Sec;
    Bounce  add10Sec;
    Bounce  reset;
    Timer   mTimer;
};


#endif
