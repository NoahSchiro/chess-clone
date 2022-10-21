#pragma once

#include "piece.h"

class King : public Piece {
public:

	//Null constructor
	King() = default;

	King(Players     color,
		 Coordinates position);

	//Because pieces do not have access to state, this will return a simplified
	//version of the possible moves based on the information it has. This means
	//that it won't understand the concept of castling. This function is generally
	//called by board and is added to/subtracted from based on the state of the board.
	std::vector<Coordinates> generateValidMoves();
};