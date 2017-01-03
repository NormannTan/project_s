#include "StarShip.h"

StarShip::StarShip()	
{} // nothing required as it is a default constuctor

double StarShip::GetCurrHp()
{
	return currHp;
} //returns the current hp

double StarShip::GetMaxHp()
{
	return maxHp;
}//return the max hp

void StarShip::ResetHp()
{
	currHp = maxHp;
} // set the current hp to max hp

bool StarShip::IsAlive()
{
	return (currHp > 0);		//used to check if ship is still alive
}

void StarShip::ReduceCurrHp (double damage) //function used to reduce currHp of ship
{
	if(damage <currHp)			// check if damage is more than hp
	{
		currHp -= damage;		// if not than currHp - damage
	}
	else
	{
		currHp = 0;											// if not than ship dies
	}
}

void StarShip::Print() //Prints out all the relevant info the player needs
{
	cout<<"Name:"<<name<<endl;
	cout<<"Hp:"<<currHp<<"/"<<maxHp<<endl;
}

string StarShip::GetName()
{
	return name;	 //return name
}
Bullet* StarShip::HandleInput(SDL_Event *event,Mix_Chunk* frigateSound)
{
	if(event->type == SDL_KEYDOWN)
	{
		Bullet* temp;
		switch(event->key.keysym.sym)
		{
		case SDLK_LEFT: 
			{
				this->currentAnimation = 2;
				xVel -= maxSpeed;break;
			}
		case SDLK_RIGHT: 
			{
				this->currentAnimation = 1;
				xVel += maxSpeed;break;
			}
		case SDLK_SPACE:
			{
				this->currentAnimation = 5;
				Mix_PlayChannel( -1, frigateSound, 0 );
				return Shoot();break;
			}
		}
		return NULL;
	}
	else if(event->type == SDL_KEYUP)
	{
		switch(event->key.keysym.sym)
		{
		case SDLK_LEFT: 
			{
				this->currentAnimation = 0;
				xVel += maxSpeed;break;
			}
		case SDLK_RIGHT: 
			{
				this->currentAnimation = 0;
				xVel -= maxSpeed;break;
			}
		}
	}
	return NULL;
}