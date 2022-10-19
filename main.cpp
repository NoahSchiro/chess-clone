#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	std::cout << "Move 0:\n";
	myBoard.cliShow();

	//"From" selects a pawn
	Coordinates from(1,1);

	//"To" directs it one unit forward
	Coordinates to(1,2);

	//Move the piece
	myBoard.movePiece(from, to);

	std::cout << "Move 1:\n";
	myBoard.cliShow();

	return 0;
}