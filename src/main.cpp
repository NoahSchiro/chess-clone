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

	//Storage spot for where we might want to move a piece
	std::vector<Coordinates> validMoves = {};
	Piece* pieceToMove = nullptr;

	//Who's turn it is. Always starts, white, but
	//alternates on a successful move
	Players turn = Players::WHITE;

    SDL_Event e;
    bool quit = false;
	while(!quit) {

	    SDL_Event e;
	    SDL_PollEvent(&e);

	    //Handle events
	    switch(e.type) {
	    	
	    	//Quit condition
    		case SDL_QUIT:
    			quit = true;
    		break;

    		//Keypress
    		case SDL_KEYDOWN:

    			if(e.key.keysym.sym == SDLK_q) {
    				quit = true;
    			}
    			
    		break;

    		//Mouse press
    		case SDL_MOUSEBUTTONDOWN:

    			myHandler.clickHandler(x,y);
    		break;

    		default : {}
    	}

    	bool validMoveFlag = false;
    	
    	//Check if we have clicked somewhere that would be a valid move
    	for(auto it : validMoves) {
    		if(x == it.x && y == it.y) {
    			validMoveFlag = true;
    		}
    	}

    	//If we clicked out of bounds of board, then reset
    	if(x < 0 || x > 7 ||
    	   y < 0 || y > 7) {

    		validMoves = {};
    		pieceToMove = nullptr;
    		x = -1;
    		y = -1;
    	
    	//If we have not already established we want to move a piece
    	//and we have clicked on something that is the same color as the turn
    	} else if (!pieceToMove && myBoard.m_board[y][x]->getColor() == turn) {
			
			//Generate the valid moves for that piece
			validMoves  = myBoard.m_board[y][x]->generateValidMoves(myBoard.m_board);
			pieceToMove = myBoard.m_board[y][x];

		//If we have no piece to move and we clicked on blank space, reset
    	} else if (!pieceToMove) {

    		validMoves = {};
    		pieceToMove = nullptr; 

    	//If we have a piece to move and haven't clicked anywhere else yet
    	} else if (pieceToMove && 
    		       x == pieceToMove->getPosition().x && 
    		       y == pieceToMove->getPosition().y) {

    		//Then do nothing really

    	//If we have a piece to move and we clicked on a space that the piece can move to
    	} else if (pieceToMove && validMoveFlag) {

    		//Set up where we will be moving to
    		Coordinates moveFrom = pieceToMove->getPosition();
    		Coordinates moveTo;
    		moveTo.x = x;
    		moveTo.y = y;

    		//Move piece
    		myBoard.movePiece(moveFrom, moveTo);

    		//Reset everything
    		validMoves  = {};
    		pieceToMove = nullptr;
    		x = -1;
    		y = -1;

    		//Alternate who's turn it is
    		turn = Players::WHITE == turn ? Players::BLACK : Players::WHITE;

    	//If we have a piece to move but have clicked off somewhere else, reset
    	} else if (pieceToMove && !validMoveFlag) {

    		validMoves  = {};
    		pieceToMove = nullptr;
			x = -1;
    		y = -1;

    	} else {
    		std::cout << "Unreachable! Should never execute!\n";
    	}

        myHandler.update(myBoard.m_board, validMoves, Players::BLACK);

        //Delay 10 millisecond
        SDL_Delay(10);
    }

	return 0;
}