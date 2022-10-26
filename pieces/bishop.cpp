#include "bishop.h"

Bishop::Bishop(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::BISHOP, color, position) {}


std::vector<Coordinates> Bishop::generateValidMoves(Piece* board[8][8]) {
	return {};
}

bool Bishop::getFirstMove() {
	return false;
}

void Bishop	::setFirstMove(bool input) {}