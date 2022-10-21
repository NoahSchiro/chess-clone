#include "pawn.h"

Pawn::Pawn(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::PAWN, color, position) {}

std::vector<Coordinates> Pawn::generateValidMoves() {
	return {};
}
