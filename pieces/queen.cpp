#include "queen.h"

Queen::Queen(Players     color,
		     Coordinates position)
	: Piece(PieceTypes::QUEEN, color, position) {}

std::vector<Coordinates> Queen::generateValidMoves(const Piece* state) {

	return {};
}