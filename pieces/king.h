#pragma once

#include "piece.h"

class King : public Piece {
public:

	//Null constructor
	King() = default;

	King(Players     color,
		 Coordinates position);

	virtual std::vector<Coordinates> generateValidMoves(const Piece* state);
};