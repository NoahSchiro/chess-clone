#include <iostream>

#include "board.h"

int main() {

	//Instatiate a new game
	Board myBoard;

	std::cout << "Move 0:\n";
	myBoard.cliShow();

	//"From" selects a pawn
	Coordinates from(1,1);

	//"To" directs it directly
	//to the king of the opposite
	//side. Just to see that it can capture
	Coordinates to(4,7);

	//Move the piece
	myBoard.movePiece(from, to);

	std::cout << "Move 1:\n";
	myBoard.cliShow();

	return 0;
}