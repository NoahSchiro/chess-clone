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


void Piece::setType(PieceTypes input) {
	m_type = input;
}

void Piece::setColor(Players input) {
	m_color = input;
}

void Piece::setPosition(Coordinates input) {
	m_position = input;
}

std::vector<Coordinates> Piece::generateValidMoves(const Piece* state) {

	return {};

}