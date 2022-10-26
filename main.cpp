#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	std::cout << "Move 0:\n";
	myBoard.cliShow();

	//Access the kings moves
	std::vector<Coordinates> moves = myBoard.m_board[6][1]->generateValidMoves(myBoard.m_board);

	for(auto it : moves) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	Coordinates from(1, 6);
	Coordinates to  (1, 2);

	myBoard.movePiece(from, to);


	std::cout << "Move 1:\n";
	myBoard.cliShow();

	//Access the kings moves
	std::vector<Coordinates> moves2 = myBoard.m_board[2][1]->generateValidMoves(myBoard.m_board);

	for(auto it : moves2) {
		int xPos = it.x;
		int yPos = it.y;
		std::cout << "(" << xPos << ", " << yPos << ")\n";
	}

	return 0;
}