#ifndef FRIGATEBULLET_H
#define FRIGATEBULLET_H
#include "Bullet.h"

class FrigateBullet : public Bullet
{
public:
	FrigateBullet(int positionX,int positionY);
	bool Move(SDL_Rect ship);
	void Show(SDL_Surface* spriteSheet,SDL_Surface* screen);
	
};

#endif