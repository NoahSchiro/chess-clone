#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	myBoard.cliShow();

	//Let's say that it is NOT this pawn's first move
	myBoard.m_board[1][6]->setFirstMove(false);

	//Access the pawn
	std::vector<Coordinates> moves = myBoard.m_board[1][6]->generateValidMoves();

	for(auto it : moves) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	return 0;
}