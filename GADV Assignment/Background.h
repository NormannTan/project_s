#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SDL.h"
#include "utility.h"
#include "Global.h"
using namespace std;
class Background
{
private:
	SDL_Rect backgroundClipA;
	SDL_Rect backgroundClipB;
	bool backgroundATurn;
	bool backgroundBTurn;
public:
	Background();
	void scroll(SDL_Surface* backgroundImage,SDL_Surface* screen);

};

#endif