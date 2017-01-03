#ifndef FRIGATE_H
#define FRIGATE_H
#include "StarShip.h"
class Frigate : public StarShip // a child of StarShip Class
{
public:	//function and methodz
	Frigate(bool player);  //constructor
	bool ReduceCurrHp(Bullet* bullet);
	void Show(SDL_Surface* frigateImage,SDL_Surface* backgroundImage);
	Bullet* Shoot();
	void Move();
};
#endif