#include <iostream>
#include "rook.h"

Rook::Rook(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::ROOK, color, position) {}

std::vector<Coordinates> Rook::generateValidMoves(Piece* board[8][8], std::vector<Coordinates> tilesInThreat) {

	std::vector<Coordinates> ans;
	Coordinates temp(m_position.x, m_position.y);

	//Figure out what color we want to attack
	Players opposite;
	if(m_color == Players::WHITE) {
		opposite = Players::BLACK;
	} else {
		opposite = Players::WHITE;
	}

	//Move one to the right
	temp.x--;

	//Get all the moves to the right
	while(temp.x >= 0) {
		
		//If the space is occupied, we cannot that
		//space or any spaces beyond it
		if(board[temp.y][temp.x]->getColor() == m_color) {
			break;
		
		//If we hit a space that is the other
		//player, we can add that as a valid move but none after it	
		} else if (board[temp.y][temp.x]->getColor() == opposite) {
			
			ans.push_back(temp);
			break;

		} else {
			ans.push_back(temp);
			temp.x--;
		}
	}

	//Move one to the left of our position
	temp.x = m_position.x + 1;
	
	//Get all the moves to the left
	while(temp.x <= 7) {

		//If the space is occupied, we cannot that
		//space or any spaces beyond it
		if(board[temp.y][temp.x]->getColor() == m_color) {
			break;

		//If we hit a space that is the other
		//player, we can add that as a valid move but none after it	
		} else if (board[temp.y][temp.x]->getColor() == opposite) {
			
			ans.push_back(temp);
			break;

		} else {
			ans.push_back(temp);
			temp.x++;
		}
	}

	//Move to one above our position
	temp.x = m_position.x;
	temp.y = m_position.y - 1;

	//Get all the moves going up
	while(temp.y >= 0) {

		//If the space is occupied, we cannot that
		//space or any spaces beyond it
		if(board[temp.y][temp.x]->getColor() == m_color) {
			break;

		//If we hit a space that is the other
		//player, we can add that as a valid move but none after it	
		} else if (board[temp.y][temp.x]->getColor() == opposite) {

			ans.push_back(temp);
			break;

		} else {
			ans.push_back(temp);
			temp.y--;
		}
	}

	//Move to one below out position
	temp.y = m_position.y + 1;

	//Get all the moves going down
	while(temp.y <= 7) {

		//If the space is occupied, we cannot that
		//space or any spaces beyond it
		if(board[temp.y][temp.x]->getColor() == m_color) {
			break;

		//If we hit a space that is the other
		//player, we can add that as a valid move but none after it
		} else if (board[temp.y][temp.x]->getColor() == opposite) {

			ans.push_back(temp);
			break;

		} else {
			ans.push_back(temp);
			temp.y++;			
		}
	}

	return ans;
}

bool Rook::getFirstMove() {
	return m_firstMove;
}

void Rook::setFirstMove(bool input) {
	m_firstMove = input;
}