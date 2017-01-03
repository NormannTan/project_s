#ifndef UTILITY_H
#define UTILITY_H

#include <SDL.h>
#include <string>
using namespace std;

SDL_Surface* load_image(string filename);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);

#endif