#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	std::cout << "Move 0:\n";
	myBoard.cliShow();

	//Access the kings moves
	std::vector<Coordinates> moves = myBoard.m_board[7][4]->generateValidMoves(myBoard.m_board);

	for(auto it : moves) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	Coordinates from(4, 7);
	Coordinates to  (4, 4);

	myBoard.movePiece(from, to);
	myBoard.cliShow();

	std::cout << "Move 1:\n";

	//Access the kings moves
	std::vector<Coordinates> moves2 = myBoard.m_board[4][4]->generateValidMoves(myBoard.m_board);

	for(auto it : moves2) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	return 0;
}