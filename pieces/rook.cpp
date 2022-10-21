#include "rook.h"

Rook::Rook(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::ROOK, color, position) {}


std::vector<Coordinates> Rook::generateValidMoves() {

	return {};
}

