#include "knight.h"

Knight::Knight(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::KNIGHT, color, position) {}


std::vector<Coordinates> Knight::generateValidMoves() {

	return {};
}
