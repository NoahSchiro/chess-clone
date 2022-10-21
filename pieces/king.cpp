#include "king.h"

#include <iostream>

King::King(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::KING, color, position) {}


std::vector<Coordinates> King::generateValidMoves() {

	//Defining the possible move set for a king is pretty easy
	//We only really need to consider the test case where we are
	//on the edges of the board
	std::vector<Coordinates> ans;
	Coordinates temp;

	//Left
	if(m_position.x != 0) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y;
		ans.push_back(temp);
	}

	//Top left
	if(m_position.x != 0 || m_position.y != 0) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y - 1;
		ans.push_back(temp);
	}

	//Top
	if(m_position.y != 0) {
		temp.x = m_position.x;
		temp.y = m_position.y - 1;
		ans.push_back(temp);
	}

	//Top right
	if(m_position.x != 7 && m_position.y != 0) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y - 1;
		ans.push_back(temp);
	}

	//Right
	if(m_position.x != 7) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y;
		ans.push_back(temp);
	}

	//Bottom right
	if(m_position.x != 7 && m_position.y != 7) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y + 1;
		ans.push_back(temp);
	}

	//Bottom
	if(m_position.y != 7) {
		temp.x = m_position.x;
		temp.y = m_position.y + 1;
		ans.push_back(temp);
	}

	//Bottom left
	if(m_position.x != 0 && m_position.y != 7) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y + 1;
		ans.push_back(temp);
	}

	return ans; 
}