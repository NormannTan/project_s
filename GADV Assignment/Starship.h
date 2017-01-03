#ifndef STARSHIP_H
#define STARSHIP_H
#include "Global.h"
#include "FrigateBullet.h"
#include <string>
#include <iostream>
using namespace std;

//creating Class StarShip
class StarShip
{
private:						
	double currHp;		//currHp which represent the health of the ship
protected:					// Placed in protected so it will be easier 
	string name;			//for the child constructor to modify the values
	double maxHp;
	int xVel;
	int maxSpeed;
	int currentAnimation;
	bool player;
public:					// functions/methods of the StarShip Class
	StarShip();
	SDL_Rect box;
	double GetCurrHp();
	double GetMaxHp();
	void ReduceCurrHp(double);
	virtual bool ReduceCurrHp(Bullet* bullet) = 0;
	void ResetHp();
	bool IsAlive();
	void Print();
	string GetName();
	virtual void Show(SDL_Surface* frigateImage,SDL_Surface* backgroundImage) = 0;
	Bullet* HandleInput(SDL_Event *event,Mix_Chunk*);
	virtual Bullet* Shoot() = 0;
	
};
#endif