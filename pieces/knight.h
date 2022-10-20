#pragma once

#include "piece.h"

class Knight : public Piece {
public:

	//Null constructor
	Knight() = default;

	Knight(Players     color,
		   Coordinates position);

	virtual std::vector<Coordinates> generateValidMoves(const Piece* state) override;

};