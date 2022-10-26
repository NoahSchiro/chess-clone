#include <iostream>
#include "rook.h"

Rook::Rook(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::ROOK, color, position) {}

std::vector<Coordinates> Rook::generateValidMoves(Piece* board[8][8]) {

	std::vector<Coordinates> ans;
	Coordinates temp(m_position.x, m_position.y);

	temp.x--;
	//Get all the moves to the right
	while(temp.x >= 0) {
		ans.push_back(temp);
		temp.x--;
	}

	temp.x = m_position.x + 1;
	//Get all the moves to the left
	while(temp.x <= 7) {
		ans.push_back(temp);
		temp.x++;
	}

	temp.x = m_position.x;
	temp.y = m_position.y - 1;
	//Get all the moves going up
	while(temp.y >= 0) {
		ans.push_back(temp);
		temp.y--;
	}

	temp.y = m_position.y + 1;
	//Get all the moves going down
	while(temp.y <= 7) {
		ans.push_back(temp);
		temp.y++;
	}

	return ans;
}

bool Rook::getFirstMove() {
	return false;
}

void Rook::setFirstMove(bool input) {}