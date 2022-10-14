#include "queen.h"

Queen::Queen(Players     color,
		     Coordinates position)
	: Piece(PieceTypes::QUEEN, color, position) {}