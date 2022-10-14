#include "piece.h"

Piece::Piece() {
	m_empty = true;
}

Piece::Piece(PieceTypes type,
				  Players color,
				  unsigned int locX,
				  unsigned int locY) {

	m_type = type;
	m_player = color;
	m_locX = locX;
	m_locY = locY;
	m_empty = false;
}