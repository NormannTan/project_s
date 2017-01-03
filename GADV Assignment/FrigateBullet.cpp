#include "FrigateBullet.h"


FrigateBullet::FrigateBullet(int positionX,int positionY)
{
	this->next = NULL;
	this->yVel = 5;
	this->box.x = positionX;
	this->box.y = positionY;
	this->box.w = 4;
	this->box.h = 12;
	this->type = FRIGATE_BULLET;
	this->capAtk = 120;
	this->frigAtk = 60 ;	
	this->craftAtk = 45;
}
bool FrigateBullet::Move(SDL_Rect ship)
{
	yVel++;
	box.y -= yVel;
	return this->CollisionDetection(ship);
}

void FrigateBullet::Show(SDL_Surface* spriteSheet, SDL_Surface* screen)
{
	SDL_Rect temp = playerFriBulletClip;
	apply_surface(box.x,box.y,spriteSheet,screen,&temp);
}

