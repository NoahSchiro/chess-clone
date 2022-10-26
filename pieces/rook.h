#pragma once

#include "piece.h"

class Rook : public Piece {
public:

	//Null constructor
	Rook() = default;

	Rook(Players     color,
		 Coordinates position);


	virtual std::vector<Coordinates> generateValidMoves(Piece* board[8][8]) override;

	//Getters
	bool getFirstMove() override;

	//Setters
	void setFirstMove(bool) override;
};