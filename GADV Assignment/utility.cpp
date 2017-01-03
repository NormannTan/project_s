#include "utility.h"
#include "SDL_image.h"

SDL_Surface* load_image( string filename )
{
	SDL_Surface* loadedImage = NULL;	// store image loaded
	SDL_Surface* optimizedImage = NULL;	// the optimized image
	loadedImage = IMG_Load( filename.c_str() );	// load the image

	if(loadedImage != NULL)
	{
		//Create optimized image
		optimizedImage = SDL_DisplayFormat( loadedImage);

		//free old image
		SDL_FreeSurface(loadedImage);
	}
	if(optimizedImage != NULL)
	{
		// colorkey
		Uint32 colorkey = SDL_MapRGB(optimizedImage->format,0xFF,0,0xFF);
		SDL_SetColorKey(optimizedImage,SDL_RLEACCEL |SDL_SRCCOLORKEY, colorkey);
	}
	return optimizedImage;
}

void apply_surface(int x,int y,SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source,clip,destination,&offset);
}