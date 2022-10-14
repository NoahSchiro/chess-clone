#pragma once

#include "piece.h"

class Knight : public Piece {
public:

	//Null constructor
	Knight() = default;

	Knight(Players     color,
		   Coordinates position);
};