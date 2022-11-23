#include <iostream>
#include <chrono>		//For benchmarking

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

	//Storage spot for what tiles are in threat. This will be
	//used to compute check/checkmate
	std::vector<Coordinates> whiteTilesInThreat;
	std::vector<Coordinates> blackTilesInThreat;

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

    			myHandler.clickHandler(x,y, turn);
    		break;

    		default : {}
    	}

    	//Check if either king is in check / checkmate
    	GameState check = myBoard.isCheckmate(whiteTilesInThreat, blackTilesInThreat);

    	if(check == GameState::WHITE_CHECKMATE) {
    		std::cout << "White is in checkmate!\n";
    		break;
    	} else if (check == GameState::BLACK_CHECKMATE) {
    		std::cout << "Black is in checkmate!\n";
    		break;
    	}

    	//Check if we have clicked somewhere that would be a valid move
    	bool validMoveFlag = false;
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
			//Note we cannot generate these moves if we are in check
			if(

			   //If we white king is in check and it's white's turn
			   (turn == Players::WHITE && check != GameState::WHITE_CHECK) ||
			   
			   //If the black king is in check and it's black's turn
			   (turn == Players::BLACK && check != GameState::BLACK_CHECK) ||
			   
			   //If we select the king
			   (myBoard.m_board[y][x]->getColor() == turn && myBoard.m_board[y][x]->getType() == PieceTypes::KING)) {
				
				//Then we can move
				if(myBoard.m_board[y][x]->getColor() == Players::WHITE) {
				
					validMoves  = myBoard.m_board[y][x]->generateValidMoves(myBoard.m_board, whiteTilesInThreat);
				
				} else {
				
					validMoves  = myBoard.m_board[y][x]->generateValidMoves(myBoard.m_board, blackTilesInThreat);
				
				}
				
				pieceToMove = myBoard.m_board[y][x];
			}

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

        myHandler.update(myBoard.m_board, validMoves, turn);

        //Delay 10 millisecond
        SDL_Delay(10);
    }

	return 0;
}