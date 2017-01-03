
#include "Global.h"
#include "Background.h"
#include "Frigate.h"
#include "BulletLinkList.h"
using namespace std;

int main( int argc, char* args[] )
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event event;
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

	//load all images
	SDL_Surface* spriteSheet ;
	SDL_Surface* backgroundImage ;
	SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32,SDL_SWSURFACE);

	//Load Music
	Mix_Chunk  *frigateSound = Mix_LoadWAV( "MacShot.wav" );
	Mix_Chunk *craftSound = Mix_LoadWAV("smallShot.wav");
	Mix_Music *music = Mix_LoadMUS( "DigitalStream.wav" );

	backgroundImage = load_image("background.png");
	spriteSheet = load_image("spriteSheet.png");
	if(backgroundImage == NULL)
	{
		return 0;
	}
	bool enemyDeleted = false;
	bool enemyDead = false;

	Background* starMap = new Background();
	//Create player Ship
	Frigate* player = new Frigate(true);
	//Create Enemy Ship
	Frigate* enemy = new Frigate(false);

	//Check Sound Loop
	bool soundLoop = true;

	BulletLinkList* playerBulletList = new BulletLinkList(enemy);
	//Create Frame Rate
	Timer fps;
	//if game is running
	bool running = true;
	int frameTrack= 0;
	//Game Loop

	while(running)
	{
		//Mix_PlayChannel( -1, frigateSound, 0 );
		if(soundLoop)
		{
			soundLoop = Mix_PlayMusic( music, -1 )  ;
		}
		starMap->scroll(backgroundImage,screen);
		fps.start();
		while(SDL_PollEvent(&event))
		{
			Bullet* temp = player->HandleInput(&event,frigateSound);
			//Bullet* temp = test->bulletButton(&event);
			if(temp != NULL)
			{
				playerBulletList->AddToFront(temp);
			}
			//if user press the exit
			if(event.type == SDL_QUIT)
			{
				//quit program
				running = false;
			}
		}
		if(!enemyDeleted)
		{	playerBulletList->MoveAndCollideCheck();
			enemyDead = !(playerBulletList->ship->IsAlive());	
			if(enemyDead)
			{
				frameTrack++;
				if(frameTrack < 15)
				{
					SDL_Rect temp = frigateDeath[0];
					apply_surface(playerBulletList->ship->box.x,playerBulletList->ship->box.y,spriteSheet,screen,&temp);
				}
				else if(frameTrack < 30)
				{
					SDL_Rect temp = frigateDeath[1];
					apply_surface(playerBulletList->ship->box.x,playerBulletList->ship->box.y,spriteSheet,screen,&temp);
				}
				else if(frameTrack < 45)
				{
					SDL_Rect temp = frigateDeath[2];
					apply_surface(playerBulletList->ship->box.x,playerBulletList->ship->box.y,spriteSheet,screen,&temp);
				}
				else
				{
					delete playerBulletList->ship;
					enemyDeleted = true;
				}
			}
			else
			{
				enemy->Move();
				enemy->Show(spriteSheet,screen);
			}
		}
		playerBulletList->RemoveOutScreen();
		player->Move();
		player->Show(spriteSheet,screen);
		playerBulletList->ShowAllBullet(spriteSheet,screen);

		//update the screen
		if(SDL_Flip(screen) == -1)
		{
			return 1;
		}
		// cap frame rate
		if(fps.get_ticks() < 1000/ FRAMES_PER_SECOND)
		{
			SDL_Delay((1000/FRAMES_PER_SECOND) - fps.get_ticks());
		}


	}
	SDL_Quit();
	return 0;
}


