#include "bishop.h"

Bishop::Bishop(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::BISHOP, color, position) {}


std::vector<Coordinates> Bishop::generateValidMoves() {
	return {};
}

bool Bishop::getFirstMove() {
	return false;
}

void Bishop	::setFirstMove(bool input) {}