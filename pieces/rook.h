#pragma once

#include "piece.h"

class Rook : public Piece {
public:

	//Null constructor
	Rook() = default;

	Rook(Players     color,
		 Coordinates position);


	virtual std::vector<Coordinates> generateValidMoves(const Piece* state) override;
};