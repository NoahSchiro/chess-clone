#include "king.h"

King::King(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::KING, color, position) {}