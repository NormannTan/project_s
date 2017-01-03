#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	// time start
	int  startTicks;

	//time stored when paused
	int pausedTicks;

	//time status
	bool paused;
	bool started;

public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();

	//get time
	int get_ticks();

	//check status
	bool is_started();
	bool is_paused();
};

#endif