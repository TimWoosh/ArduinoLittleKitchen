//Oven.h

#ifndef LK_OVEN
#define	LK_OVEN

#include <Bounce2.h>

class Oven
{
	public:
		Oven(int pin_btn_pwr, int pin_led_pwr, int pin_led_oven);
		void update();
		void switchOn();
		void switchOff();
		bool isOn();
		
		bool isHot();
		bool isCountingDown();
		
		int getTimerSec();
		void setTimerSec(int seconds);
		
		void start();
	private:
		int PIN_BTN_PWR, PIN_LED_PWR, PIN_LED_OVEN;
		int timerSec;
		bool on, hot;
		Bounce debouncerOn;
};


#endif