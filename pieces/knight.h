#pragma once

#include "piece.h"

class Knight : public Piece {
public:

	//Null constructor
	Knight() = default;

	Knight(Players     color,
		   Coordinates position);


	//Because pieces do not have access to state, this will return a simplified
	//version of the possible moves based on the information it has. This means
	//that it won't understand that it can't collide with other objects. This 
	//function is generally called by board and is added to/subtracted 
	//from based on the state of the board.
	std::vector<Coordinates> generateValidMoves() override;

	//Getters
	bool getFirstMove() override;

	//Setters
	void setFirstMove(bool) override;
};