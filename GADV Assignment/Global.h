#ifndef GLOBAL_H
#define GLOBAL_H
#include "SDL.h"
#include "SDL_image.h"
#include "utility.h"
#include "Timer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SDL_mixer.h"
	const int SCREEN_WIDTH = 320;
	const int SCREEN_HEIGHT = 480;
	const int FRAMES_PER_SECOND = 60;
	const int FRIGATE_WIDTH = 28;
	const int FRIGATE_HEIGHT = 56;
	const int CRAFT_BULLET = 0;
	const int FRIGATE_BULLET = 1;
	const int CAPITAL_BULLET = 2;
	static const SDL_Rect playerFriBulletClip ={238,171,4,12};
	static const SDL_Rect playerFrigate[6] = {{2,68,FRIGATE_WIDTH,FRIGATE_HEIGHT},{34,68,FRIGATE_WIDTH,FRIGATE_HEIGHT},{66,68,FRIGATE_WIDTH,FRIGATE_HEIGHT},
																				{98,68,FRIGATE_WIDTH,FRIGATE_HEIGHT},{130,68,FRIGATE_WIDTH,FRIGATE_HEIGHT},{162,68,FRIGATE_WIDTH,FRIGATE_HEIGHT}};
	static const SDL_Rect computerFrigate[6] = {{2,132,FRIGATE_WIDTH,FRIGATE_HEIGHT},{34,132,FRIGATE_WIDTH,FRIGATE_HEIGHT},{66,132,FRIGATE_WIDTH,FRIGATE_HEIGHT},
																				{98,132,32,FRIGATE_HEIGHT},{130,132,FRIGATE_WIDTH,FRIGATE_HEIGHT},{162,132,FRIGATE_WIDTH,FRIGATE_HEIGHT}};
	static const SDL_Rect frigateDeath[3] = {{192,64,32,64},{224,64,32,64},{192,128,32,64}};
	int const GAME_STATE_START = 1;
	int const GAME_STATE_BATTLE = 2;
	/*static SDL_Surface* spriteSheet = load_image("SpriteSheet.png");
	static SDL_Surface* backgroundImage = load_image("BackGround.png");
	static SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE);*/
#endif