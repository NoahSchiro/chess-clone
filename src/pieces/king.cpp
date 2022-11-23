#include "king.h"

#include <iostream>

King::King(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::KING, color, position) {}


std::vector<Coordinates> King::generateValidMoves(Piece* board[8][8], std::vector<Coordinates> tilesInThreat) {

	//Defining the possible move set for a king is pretty easy
	//We only really need to consider the test case where we are
	//on the edges of the board
	std::vector<Coordinates> ans;
	Coordinates temp;

	//Left
	if(m_position.x > 0) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Top left
	if(m_position.x > 0 && m_position.y > 0) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y - 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Top
	if(m_position.y > 0) {
		temp.x = m_position.x;
		temp.y = m_position.y - 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Top right
	if(m_position.x < 7 && m_position.y > 0) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y - 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Right
	if(m_position.x < 7) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Bottom right
	if(m_position.x < 7 && m_position.y < 7) {
		temp.x = m_position.x + 1;
		temp.y = m_position.y + 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Bottom
	if(m_position.y < 7) {
		temp.x = m_position.x;
		temp.y = m_position.y + 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//Bottom left
	if(m_position.x > 0 && m_position.y < 7) {
		temp.x = m_position.x - 1;
		temp.y = m_position.y + 1;

		//Only a valid move if the space is empty
		//or it's the opposite color
		if(board[temp.y][temp.x]->getColor() != m_color) {
			ans.push_back(temp);
		}
	}

	//If the king has not moved
	if(m_firstMove) {

		int tx = m_position.x;
		int ty = m_position.y;

		//King side castle?
		if(m_color == Players::WHITE &&							//If we are on the white side, and;
		   board[ty][tx-1]->getType() == PieceTypes::NONE &&	//the bishop has moved, and;
		   board[ty][tx-2]->getType() == PieceTypes::NONE &&	//the knight has moved, and;
		   board[0][0]->getFirstMove()) {						//the rook has not moved

			temp.x = m_position.x - 2;
			temp.y = m_position.y;
			ans.push_back(temp);

		} else if (m_color == Players::BLACK &&							//If we are on the black side, and;
		   		   board[ty][tx-1]->getType() == PieceTypes::NONE &&	//the bishop has moved, and;
		   		   board[ty][tx-2]->getType() == PieceTypes::NONE &&	//the knight has moved, and;
		   		   board[7][0]->getFirstMove()) {						//the rook has not moved

			temp.x = m_position.x - 2;
			temp.y = m_position.y;
			ans.push_back(temp);

		}

		//Queen side castle?
		if(m_color == Players::WHITE &&							//If we are on the white side, and;
		   board[ty][tx+1]->getType() == PieceTypes::NONE &&  	//the queen has moved, and;
		   board[ty][tx+2]->getType() == PieceTypes::NONE &&	//the bishop has moved, and;
		   board[ty][tx+3]->getType() == PieceTypes::NONE &&	//the knight has moved, and;
		   board[0][7]->getFirstMove()) {						//the rook has not moved

			temp.x = m_position.x + 2;
			temp.y = m_position.y;
			ans.push_back(temp);

		} else if (m_color == Players::BLACK &&							//If we are on the black side, and;
		   		   board[ty][tx+1]->getType() == PieceTypes::NONE && 	//the queen has moved, and;
		   		   board[ty][tx+2]->getType() == PieceTypes::NONE &&	//the bishop has moved, and;
		   		   board[ty][tx+3]->getType() == PieceTypes::NONE &&	//the knight has moved, and;
		   		   board[7][7]->getFirstMove()) {						//the rook has not moved

			temp.x = m_position.x + 2;
			temp.y = m_position.y;
			ans.push_back(temp);

		}
	}

	//If a tile that is in threat
	//is in our ans, then remove it
	for(auto i : tilesInThreat) {
		for(int j = 0; j < ans.size(); j++) {
			if(i.x == ans[j].x &&
			   i.y == ans[j].y) {
				ans.erase(ans.begin() + j);
			}
		}
	}

	return ans;
}

bool King::getFirstMove() {
	return m_firstMove;
}

void King::setFirstMove(bool input) {
	m_firstMove = input;
}