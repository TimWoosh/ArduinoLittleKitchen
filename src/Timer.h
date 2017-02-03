#ifndef LK_TIMER
#define	LK_TIMER

class Timer
{
	public:
    Timer();
		int 	getSec();
    long  getMsSinceStart();
    int   getSecSinceStart();
    int   getSecLeft();
		void 	setSec(int seconds);
		void 	addSec(int seconds);
		void 	start();
		void 	pause();
    void  reset();
		void  update();
    bool  isDone();
	private:
    long  msStart;
		int 	seconds;
		bool	countingDown, done;
    long  msLast;
};

#endif
