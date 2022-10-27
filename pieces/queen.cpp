#include "queen.h"

Queen::Queen(Players     color,
		     Coordinates position)
	: Piece(PieceTypes::QUEEN, color, position) {}

std::vector<Coordinates> Queen::generateValidMoves(Piece* board[8][8]) {

	std::vector<Coordinates> ans;
	Coordinates temp(m_position.x, m_position.y);

	//Since a lot of this is a copy paste of the rook/bishop code,
	//I will just handle this from the perspective of a rook,
	//then the perspective of a bishop

	//Figure out what color we want to attack
	Players opposite;
	if(m_color == Players::WHITE) {
		opposite = Players::BLACK;
	} else {
		opposite = Players::WHITE;
	}

	//Move one to the left
	temp.x--;

	//Get all the moves to the left
	while(temp.x >= 0) {
		
		//If the space is occupied, we cannot reach that
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

	//Now for the bishop moves

	//Go into the top left 
	temp.x = m_position.x - 1;
	temp.y = m_position.y - 1;
	while(temp.x > 0 && temp.y > 0) {
		
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
	while(temp.x < 8 && temp.y > 0) {
		
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
	while(temp.x > 0 && temp.y < 8) {
		
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


bool Queen::getFirstMove() {
	return false;
}

void Queen::setFirstMove(bool input) {}