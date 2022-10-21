#pragma once

#include "piece.h"

class Pawn : public Piece {
public:

	//Null constructor
	Pawn() = default;

	Pawn(Players     color,
		 Coordinates position);


	virtual std::vector<Coordinates> generateValidMoves() override;
};