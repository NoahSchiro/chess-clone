#pragma once

#include "piece.h"

class Queen : public Piece {
public:

	//Null constructor
	Queen() = default;

	Queen(Players     color,
		  Coordinates position);

	virtual std::vector<Coordinates> generateValidMoves() override;
};