#ifndef BULLETLINKLIST_H 
#define BULLETLINKLIST_H
#include "Global.h"
#include "FrigateBullet.h"
#include "Starship.h"
class BulletLinkList
{
public:
	BulletLinkList(StarShip* ship);
	Bullet* bulletLinkList;
	StarShip* ship;
	void Remove(Bullet* toDelete);
	void RemoveOutScreen();
	bool MoveAndCollideCheck();
	void AddToFront(Bullet* newBullet);
	void ShowAllBullet(SDL_Surface* spriteSheet,SDL_Surface* screen);
};
#endif