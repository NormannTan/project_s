#include "timer.h"
#include "SDL.h"

Timer::Timer()
{
	startTicks = 0;
	pausedTicks= 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	//start the timer
	started = true;
	paused = false;
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//stop the timer
	started = false;

	//Unpause the timer
	paused = false;
}

void Timer::pause()
{
	if((started == true) && (paused == false))
	{
		paused = true;
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	//if time is paused
	
	if(paused == true)
	{
		paused = false;

		//calculate the paused ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//reset tick
		pausedTicks = 0;
	}
}

int Timer::get_ticks()
{
	if(started == true)
	{
		if(paused == true)
		{
			return pausedTicks;
		}
		else
		{
			//return the current time - start time
			return SDL_GetTicks()- startTicks;
		}
	}
	//means time is not running
	return 0;
}

bool Timer::is_started()
{
	return started;
}

bool Timer::is_paused()
{
	return paused;
}