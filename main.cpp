#include <iostream>

#include "./graphics/SDLHandler.h"
#include "board.h"

int main(int, char **) {

	//Set up intial game state
	Board myBoard;

	//Set up the sdl graphics
	SDLHandler myHandler;

    //Where we last clicked
	int x = -1;
	int y = -1;

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

    		case SDL_MOUSEBUTTONDOWN:
    			myHandler.clickHandler(x,y);
    		break;

    		default : {}
    	}

    	std::vector<Coordinates> validMoves = {};

    	//Is the last mouse click in valid coordinates?
    	if(x > -1 && x < 8 &&
    	   y > -1 && y < 8) {

    		//If we clicked on a valid piece
    		if(myBoard.m_board[y][x]->getType() != PieceTypes::NONE) {
    			//Generate the valid moves for that piece
    			validMoves = myBoard.m_board[y][x]->generateValidMoves(myBoard.m_board);
    		}
    	}

    	std::cout << validMoves.size() << "\n";

        myHandler.update(myBoard.m_board, validMoves);

        //Delay 10 millisecond
        SDL_Delay(10);
    }

	return 0;
}