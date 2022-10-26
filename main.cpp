#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	myBoard.cliShow();

	//Access the pawn
	std::vector<Coordinates> moves = myBoard.m_board[7][7]->generateValidMoves(myBoard.m_board);

	for(auto it : moves) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	return 0;
}