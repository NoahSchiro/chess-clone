#include "queen.h"

Queen::Queen(Players     color,
		     Coordinates position)
	: Piece(PieceTypes::QUEEN, color, position) {}

std::vector<Coordinates> Queen::generateValidMoves(Piece* board[8][8]) {

	return {};
}


bool Queen::getFirstMove() {
	return false;
}

void Queen::setFirstMove(bool input) {}