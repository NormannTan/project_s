#include "Bullet.h"

Bullet::Bullet()
{
}
SDL_Rect Bullet::Position()
{
	return box;
}

bool Bullet::CollisionDetection(SDL_Rect ship)
{
	int shipTop = ship.y;
	int shipBot = ship.y + ship.h;
	int shipLeft = ship.x ;
	int shipRight = ship.x + ship.w;

	int bulletTop = this->box.y;
	int bulletBot = this->box.y + this->box.h;
	int bulletLeft = this->box.x;
	int bulletRight = this->box.x + this->box.w;

	if(shipTop > bulletBot)
	{
		return false;
	}
	if(shipBot < bulletTop)
	{
  		return false;
	}
	if(shipLeft > bulletRight)
	{
		return false;
	}
	if(shipRight < bulletLeft)
	{
		return false;
	}
	return true;
}
