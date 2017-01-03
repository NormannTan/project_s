#ifndef UTILITY_H
#define UTILITY_H
#include <SDL.h>
#include <string>
using namespace std;

//load image
SDL_Surface* load_image( string filename);

//apply surface
void apply_surface(int x,int y, SDL_Surface* source, SDL_Surface* destination,SDL_Rect* clip);

#endif