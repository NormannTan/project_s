#include "BulletLinkList.h"

BulletLinkList::BulletLinkList(StarShip* ship)
{
	this->bulletLinkList = NULL;
	this->ship = ship;
}

void BulletLinkList::Remove(Bullet* toDelete)
{
				if(toDelete == bulletLinkList)
				{
					bulletLinkList = bulletLinkList->next;
				}
				else
				{
					Bullet* previous = bulletLinkList;
					while(previous->next != toDelete)
					{
						previous = previous->next;
					}
					previous->next = toDelete->next;
				}
				delete toDelete;
}

void BulletLinkList::RemoveOutScreen()
{
	if(bulletLinkList !=NULL)
	{
		Bullet* current = bulletLinkList;
		bool deleteNeeded = false;
		Bullet* toDelete = NULL;
		while(current!= NULL)
		{
			if( !(current->Position().y <1920 && current->Position().y > -50))
			{
				toDelete = current; 
				deleteNeeded = true;
			}
			if(current != NULL)
				current = current->next;
			if(deleteNeeded)
			{
				BulletLinkList::Remove(toDelete);
				deleteNeeded = false;
			}
		}
	}
}
void BulletLinkList::AddToFront(Bullet* newBullet)
{
		for(Bullet* current = newBullet; current!= NULL; current = current->next)
		{
			if(current->next == NULL)
			{
 				current->next = bulletLinkList;
				break;
			}
		}
		bulletLinkList = newBullet;
}
bool BulletLinkList::MoveAndCollideCheck()
{
	if(bulletLinkList == NULL)
	{
		return false;
	}
	else
	{
		Bullet* temp = bulletLinkList;
		Bullet* toDelete = NULL;
		bool needDelete = false;
		while(temp != NULL)
		{
			bool ifCollide = temp->Move(this->ship->box);
			if(ifCollide)
			{
				bool ifDead = ship->ReduceCurrHp(temp);
				if(!ifDead)
				{
					
					return true;
				}
				cout<<this->ship->GetCurrHp();
				toDelete = temp;
				needDelete = true;
			}		
			temp = temp->next;
			if(needDelete)
			{
				this->Remove(toDelete);
				needDelete = false;
			}
		}
	}
	return false;
}

void BulletLinkList::ShowAllBullet(SDL_Surface* spriteSheet,SDL_Surface* screen)
{
	if(bulletLinkList != NULL)
	{
		for(Bullet* temp = bulletLinkList; temp != NULL; temp = temp->next)
		{
			temp->Show(spriteSheet,screen);
		}
	}
}