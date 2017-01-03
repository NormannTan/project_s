#ifndef BULLET_H
#define BULLET_H
#include "Global.h"
class Bullet
{
protected:
	SDL_Rect box;
	int yVel;
	int type ;
public:	
	Bullet* next;
	Bullet();
	virtual bool Move(SDL_Rect ship) = 0;
	virtual void Show(SDL_Surface*,SDL_Surface*) = 0;
	SDL_Rect Position();
	bool CollisionDetection(SDL_Rect box);
	double capAtk;
	double frigAtk;	
	double craftAtk;
};

#endif