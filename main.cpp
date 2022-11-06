#include <iostream>

#include "./graphics/SDLHandler.h"
#include "board.h"

int main(int, char **) {

	//Set up intial game state
	Board myBoard;

	//Set up the sdl graphics
	SDLHandler myHandler;

    SDL_Event e;
    bool quit = false;
	while(!quit) {

	    SDL_Event e;
	    SDL_PollEvent(&e);

	    switch(e.type) {
	    	
    		case SDL_QUIT:
    			quit = true;
    		break;

    		case SDL_KEYDOWN:

    			if(e.key.keysym.sym == SDLK_q) {
    				quit = true;
    			}
    			
    		break;

    		default : {}
    	}

        myHandler.update(myBoard.m_board);

        //Delay 10 millisecond
        SDL_Delay(10);
    }

	return 0;
}