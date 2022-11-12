#pragma once

#include "piece.h"

class Pawn : public Piece {
public:

	//Null constructor
	Pawn() = default;

	Pawn(Players     color,
		 Coordinates position);

	virtual std::vector<Coordinates> generateValidMoves(Piece* board[8][8]) override;

	//Getters
	bool getFirstMove() override;

	//Settes
	void setFirstMove(bool) override;
};