#pragma once
#pragma once

#include "common.cpp"
#include "./pieces/piece.h"

/*
Board is our representation of the game state:
1. What pieces are where?
2. Who's turn is it
3. Captured pieces for both sides (this will be useful when 
pawn promotion is implemented)
4. Whether or not there is a check/checkmate and for whom?
*/
class Board {
public:

	//Constructor
	Board();

	void movePiece(Coordinates from,
				   Coordinates to);

	//Prints the board to the terminal
	void cliShow();

	//The actual board (8 tiles by 8 tiles)
	Piece m_board[8][8];

private:

	//Current state of the game 
	GameState m_state;
};