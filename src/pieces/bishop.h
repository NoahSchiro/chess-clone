#pragma once

#include "piece.h"

class Bishop : public Piece {
public:

	//Null constructor
	Bishop() = default;

	Bishop(Players     color,
		   Coordinates position);


	virtual std::vector<Coordinates> generateValidMoves(Piece* board[8][8], std::vector<Coordinates> tilesInThreat) override;

	//Getters
	bool getFirstMove() override;

	//Setters
	void setFirstMove(bool) override;
};