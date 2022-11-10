#include "bishop.h"
#include <iostream>

Bishop::Bishop(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::BISHOP, color, position) {}

std::vector<Coordinates> Bishop::generateValidMoves(Piece* board[8][8]) {
		
	std::vector<Coordinates> ans;
	Coordinates temp (m_position.x, m_position.y);

	//Figure out what color we want to attack
	Players opposite;
	if(m_color == Players::WHITE) {
		opposite = Players::BLACK;
	} else {
		opposite = Players::WHITE;
	}

	//Go into the top left 
	temp.x--;
	temp.y--;
	while(temp.x >= 0 && temp.y >= 0) {
		
		//If the space is occupied, we cannot move
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
			temp.y--;
		}

	}

	//Go into the top right 
	temp.x = m_position.x + 1;
	temp.y = m_position.y - 1;
	while(temp.x < 8 && temp.y >= 0) {
		
		//If the space is occupied, we cannot move
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
			temp.y--;
		}
	}

	//Go into the bottom right 
	temp.x = m_position.x + 1;
	temp.y = m_position.y + 1;
	while(temp.x < 8 && temp.y < 8) {
		
		//If the space is occupied, we cannot move
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
			temp.y++;
		}
	}

	//Go into the bottom left 
	temp.x = m_position.x - 1;
	temp.y = m_position.y + 1;
	while(temp.x >= 0 && temp.y < 8) {
		
		//If the space is occupied, we cannot move
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
			temp.y++;
		}
	}

	return ans;
}

bool Bishop::getFirstMove() {
	return false;
}

void Bishop	::setFirstMove(bool input) {}