#include "knight.h"

Knight::Knight(Players     color,
		       Coordinates position)
	: Piece(PieceTypes::KNIGHT, color, position) {}


std::vector<Coordinates> Knight::generateValidMoves(Piece* board[8][8], std::vector<Coordinates> tilesInThreat) {

	//Defining the possible move set for a knight is pretty easy
	//We only really need to consider the test case where we are
	//on the edges of the board
	std::vector<Coordinates> ans;
	Coordinates temp;

	/*
	Diagram of where the knight can go (o denotes they 
	can move there)
	
	x o x o x
	o x x x o
	x x k x x
	o x x x o
	x o x o x
	
	*/

	//Left bottom
	if(m_position.x > 1 && m_position.y < 7) {
		temp.x = m_position.x - 2;
		temp.y = m_position.y + 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Left top
	if(m_position.x > 1 && m_position.y > 0) {
		temp.x = m_position.x - 2;
		temp.y = m_position.y - 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Top left
	if(m_position.x > 0 && m_position.y > 1) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y - 2;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Top right
	if(m_position.x < 7 && m_position.y > 1) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y - 2;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Right top
	if(m_position.x < 6 && m_position.y > 0) {
		temp.x = m_position.x + 2;
		temp.y = m_position.y - 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Right bottom
	if(m_position.x < 6 && m_position.y < 7) {
		temp.x = m_position.x + 2;
		temp.y = m_position.y + 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Bottom right
	if(m_position.x < 7 && m_position.y < 6) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y + 2;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Bottom left
	if(m_position.x > 0 && m_position.y < 6) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y + 2;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	return ans;
}

bool Knight::getFirstMove() {
	return false;
}

void Knight::setFirstMove(bool input) {}