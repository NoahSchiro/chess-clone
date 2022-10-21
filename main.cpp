#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	std::cout << "Move 0:\n";
	myBoard.cliShow();

	std::vector<Coordinates> moves = myBoard.m_board[7][4]->generateValidMoves();

	std::cout << moves.size() << "\n";

	for(auto it : moves) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	return 0;
}