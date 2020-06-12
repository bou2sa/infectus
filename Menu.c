/**
* @file Menu.c
* @brief Testing Program
* @author Boussema
* @version 0.1
* @date Jun 11,2020
*/






#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fonctions.h"


int main(int argc, char const *argv[])
{



  
  Uint32 start ;
  const int FPS= 60;


  Acteurs acteurs;
  Boutons boutons;
  Hero hero ;
 
  




   //initialisations
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

 SDL_ShowCursor(SDL_DISABLE);
  
/* appel des fonctions */

acteurs.screen= SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "INFECTUS", NULL );

    initializeHero(&hero);
    
    initialisation(&acteurs);
    update_points_de_collision(&hero);


    drawHero(hero, &acteurs);
    



int carryon = 1;
while(carryon)
{		


	    start=SDL_GetTicks();
				
		

		SDL_PollEvent(&acteurs.event);

		updatePlayer(&hero , &acteurs) ;

	centerScrollingOnPlayer(hero, &acteurs);

		drawHero(hero , &acteurs) ;

		
		SDL_Flip(acteurs.screen);






	switch(acteurs.event.type)
	{
		case SDL_QUIT:
             carryon = 0;
    	case SDL_KEYDOWN:
			if(acteurs.event.key.keysym.sym == SDLK_ESCAPE)
				{
					carryon= 0;
				}
			break;

	}

if ( 1000/FPS > SDL_GetTicks()-start )
		{
			SDL_Delay( 1000/FPS - (SDL_GetTicks()-start)) ;
		}

}




    //LIB
	SDL_Quit();
	return 0 ;

}

