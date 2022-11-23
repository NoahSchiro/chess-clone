#include "pawn.h"

Pawn::Pawn(Players     color,
		   Coordinates position)
	: Piece(PieceTypes::PAWN, color, position) {}

std::vector<Coordinates> Pawn::generateValidMoves(Piece* board[8][8], std::vector<Coordinates> tilesInThreat) {
	
	//The pawn is an interesting
	//case because it depends on it's color
	std::vector<Coordinates> ans;
	Coordinates temp;

	//If the pawn is white, it can move in the positive y direction
	if(m_color == Players::WHITE) {

		//If it's the first move, it gets one extra move
		if(m_firstMove) {
			temp.x = m_position.x;
			temp.y = m_position.y + 2;
	
			//Only a valid move if the space is empty
			if(board[temp.y][temp.x]->getColor() == Players::BLANK) {
				ans.push_back(temp);
			}
		}

		//If we have not reached the otherside of the board
		if(m_position.y != 7) {

			//The position directly in front of the pawn
			temp.x = m_position.x;
			temp.y = m_position.y + 1;

			//Only a valid move if the space is empty
			if(board[temp.y][temp.x]->getColor() == Players::BLANK) {
				ans.push_back(temp);
			}

			//The diagonal attack vectors
			if(m_position.x != 0) {
				temp.x = m_position.x - 1;
				temp.y = m_position.y + 1;

				//Only a valid move if the space is occupied by enemy
				if(board[temp.y][temp.x]->getColor() == Players::BLACK) {
					ans.push_back(temp);
				}
			}
			if(m_position.x != 7) {
				temp.x = m_position.x + 1;
				temp.y = m_position.y + 1;

				//Only a valid move if the space is occupied by enemy
				if(board[temp.y][temp.x]->getColor() == Players::BLACK) {
					ans.push_back(temp);
				}
			}
		}

	//If the pawn is black, it can move in the negative y direction
	} else {

		//If it's the first move, it gets one extra move
		if(m_firstMove) {
			temp.x = m_position.x;
			temp.y = m_position.y - 2;

			//Only a valid move if the space is empty
			if(board[temp.y][temp.x]->getColor() == Players::BLANK) {
				ans.push_back(temp);
			}
		}

		//If we have not reached the otherside of the board
		if(m_position.y != 0) {

			//The position directly in front of the pawn
			temp.x = m_position.x;
			temp.y = m_position.y - 1;

			//Only a valid move if the space is empty
			if(board[temp.y][temp.x]->getColor() == Players::BLANK) {
				ans.push_back(temp);
			}

			//The diagonal attack vectors
			if(m_position.x != 0) {
				temp.x = m_position.x - 1;
				temp.y = m_position.y - 1;
				
				//Only a valid move if the space is occupied by enemy
				if(board[temp.y][temp.x]->getColor() == Players::WHITE) {
					ans.push_back(temp);
				}
			}
			if(m_position.x != 7) {
				temp.x = m_position.x + 1;
				temp.y = m_position.y - 1;
				
				//Only a valid move if the space is occupied by enemy
				if(board[temp.y][temp.x]->getColor() == Players::WHITE) {
					ans.push_back(temp);
				}
			}


		}
	}

	return ans; 
}

bool Pawn::getFirstMove() {
	return m_firstMove;
}

void Pawn::setFirstMove(bool input) {
	m_firstMove = input;
}
