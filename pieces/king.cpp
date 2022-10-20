#include "king.h"

#include <iostream>

King::King(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::KING, color, position) {}


std::vector<Coordinates> King::generateValidMoves(const Piece* state) {
	
	std::vector<Coordinates> moves;

	//Make sure that the board and where I think I am line up
	// if(state[m_position.y][m_position.y] != this) {

	// 	std::cout << "Hey something is wrong\n";
	// }

	return {};
}