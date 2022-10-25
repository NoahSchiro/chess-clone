#include "piece.h"

Piece::Piece(PieceTypes  type,
		  	 Players     color,
		  	 Coordinates position) {

	m_type     = type;
	m_color    = color;
	m_position = position;
}

std::vector<Coordinates> Piece::generateValidMoves() {

	return {};

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

bool Piece::getFirstMove() {
	//This will generally only be used by the king,
	//pawn, and rook. Everything else, just assume it's false
	return false;
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

void Piece::setFirstMove(bool input) {}