#include "Frigate.h"


Frigate::Frigate(bool player) //constructor
{
	this->name = "Frigate";			//Assign Values according to ship type
	this->maxHp = 300;
	this->xVel = 0;
	this->maxSpeed = 5;
	this->box.w = FRIGATE_WIDTH;
	this->box.h = FRIGATE_HEIGHT;
	this->currentAnimation = 0;
	this->player = player;	
	this->ResetHp();
	if(player)
	{
		this->box.x = (SCREEN_WIDTH - FRIGATE_WIDTH)/2;
		this->box.y = SCREEN_HEIGHT - FRIGATE_HEIGHT - 10;
	}
	else
	{
		this->box.x = (SCREEN_WIDTH - FRIGATE_WIDTH)/2;
		this->box.y = 10;
	}

}


bool Frigate::ReduceCurrHp(Bullet* bullet)	//overwrite pure virtual function
{
	StarShip::ReduceCurrHp(bullet->frigAtk);					//passed into the StarShip function
	return this->IsAlive();		//check if this alive
}

void Frigate::Show(SDL_Surface*spriteSheet,SDL_Surface* backgroundImage)
{
	SDL_Rect temp;
	if(this->player)
	{
		temp = playerFrigate[currentAnimation];
	}
	else
	{
		temp = computerFrigate[currentAnimation];
	}
	apply_surface(box.x,box.y,spriteSheet,backgroundImage,&temp);
}
Bullet* Frigate::Shoot()
{
	FrigateBullet* left = new FrigateBullet(box.x+4,box.y);
	FrigateBullet* right = new FrigateBullet(box.x+25,box.y);
	left->next = right;
	return left;
}

void Frigate::Move()
{
	//moves the bird left or right
	box.x += xVel;

	if((box.x<0)||(box.x + FRIGATE_WIDTH > SCREEN_WIDTH))
	{
		box.x -= xVel;
		if(box.x > SCREEN_WIDTH/2)
		{
			box.x = SCREEN_WIDTH - FRIGATE_WIDTH;
		}
		else
		{
			box.x = 0;
		}
	}
}