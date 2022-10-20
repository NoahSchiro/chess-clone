#include "bishop.h"

Bishop::Bishop(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::BISHOP, color, position) {}


std::vector<Coordinates> Bishop::generateValidMoves(const Piece* state) {
	return {};
}
