#include "Background.h"	
Background::Background()
{
	backgroundATurn = true;
	backgroundBTurn = false;
	backgroundClipA.x = 0;
	backgroundClipA.y = 1920-SCREEN_HEIGHT;
	backgroundClipB.x = 0;
	backgroundClipB.y = 1920;
}
void Background::scroll(SDL_Surface* backgroundImage,SDL_Surface* screen)
{
		if(backgroundClipB.y <= 0)
		{
			backgroundATurn = true;
		}
		if(backgroundClipA.y <= 0)
		{
			backgroundBTurn = true;
		}
		if(backgroundATurn)
		{
			backgroundClipA.y -= 1;
			apply_surface(0,0,backgroundImage,screen,&backgroundClipA);
		}
		if(backgroundBTurn)
		{
			backgroundClipB.y -= 1;
			apply_surface(0,0,backgroundImage,screen,&backgroundClipB);
		}
		if(backgroundClipA.y < -SCREEN_HEIGHT)
		{
			backgroundATurn = false;
			backgroundClipA.y = 1920;
		}
		if(backgroundClipB.y < -SCREEN_HEIGHT)
		{
			backgroundBTurn = false;
			backgroundClipB.y = 1920;
		}
}