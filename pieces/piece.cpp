#include "piece.h"

Piece::Piece(PieceTypes  type,
		  	 Players     color,
		  	 Coordinates position) {

	m_type     = type;
	m_color    = color;
	m_position = position;
}

PieceTypes Piece::getType() {
	return m_type;
}

Players Piece::getColor() {
	return m_color;
}

Coordinates Piece::getPosition() {
	return m_position;
}

std::vector<Coordinates> Piece::generateValidMoves() {

	return {};

}