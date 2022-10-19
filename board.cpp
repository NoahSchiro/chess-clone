#include "board.h"

#include "./pieces/pawn.h"
#include "./pieces/knight.h"
#include "./pieces/bishop.h"
#include "./pieces/rook.h"
#include "./pieces/queen.h"
#include "./pieces/king.h"

#include <iostream>

//Constructor
Board::Board() {

	//The board always has the same configuration 
	//at the beginning. White moves
	m_state = GameState::WHITE_MOVE;

	//Temp variables to make our lives easier
	Players white = Players::WHITE;
	Players black = Players::BLACK;
	PieceTypes pawn   = PieceTypes::PAWN;
	PieceTypes bishop = PieceTypes::BISHOP;
	PieceTypes knight = PieceTypes::KNIGHT;
	PieceTypes rook   = PieceTypes::ROOK;
	PieceTypes queen  = PieceTypes::QUEEN;
	PieceTypes king   = PieceTypes::KING;

	//I will make one coordinate structure to modify for each item
	Coordinates pos(0, 0);

	//White back row
	m_board[0][0] = Rook(white, pos);

	pos.x = 1;
	m_board[0][1] = Knight(white, pos);
	
	pos.x = 2;
	m_board[0][2] = Bishop(white, pos);

	pos.x = 3;
	m_board[0][3] = Queen(white, pos);
	
	pos.x = 4;
	m_board[0][4] = King(white, pos);

	pos.x = 5;
	m_board[0][5] = Bishop(white, pos);

	pos.x = 6;
	m_board[0][6] = Knight(white, pos);

	pos.x = 7;
	m_board[0][7] = Rook(white, pos);

	//White & Black pawn row
	for(int i = 0; i < 8; i++) {

		Coordinates whitePos(i, 1);
		Coordinates blackPos(i, 6);

		m_board[1][i] = Pawn(white, whitePos);
		m_board[6][i] = Pawn(black, blackPos);
	}

	//For the black back row, the y position is 7
	pos.y = 7;

	//Black back row
	m_board[7][0] = Rook(black, pos);

	pos.x = 1;
	m_board[7][1] = Knight(black, pos);

	pos.x = 2;
	m_board[7][2] = Bishop(black, pos);

	pos.x = 3;
	m_board[7][3] = Queen(black, pos);
	
	pos.x = 4;
	m_board[7][4] = King(black, pos);

	pos.x = 5;
	m_board[7][5] = Bishop(black, pos);

	pos.x = 6;
	m_board[7][6] = Knight(black, pos);

	pos.x = 7;
	m_board[7][7] = Rook(black, pos);

	//For every other position, it's just a blank piece
	for(int i = 2; i < 6; i++) {
		for(int j = 0; j < 8; j++) {
			
			pos.x = j;
			pos.y = i;
			m_board[i][j] = Piece(PieceTypes::NONE, Players::BLANK, pos);
		}
	}
}

void Board::movePiece(Coordinates from,
			          Coordinates to){

	//Ensure valid coordinates
	if(from.x > 7 || from.y < 0 ||
	   to.x   > 7 || to.y   < 0) {
		return;
	}

	//We will need this several times
	Piece pieceToMove = m_board[from.y][from.x];

	//Ensure there is a piece at the "from" coordinate
	if(pieceToMove.getType() == PieceTypes::NONE) {
		return;
	}

	//The piece cannot move to a position which is
	//already occupied, unless that position is
	//of the other color

	//For the position we want to move to, is it the same color as
	//the piece we are trying to move?
	if(m_board[to.y][to.x].getColor() == pieceToMove.getColor()) {
		return;
	}

	//Assign this piece a new position

	//No matter what, the piece itself only needs to
	//know where it is now
	pieceToMove.setPosition(to);

	//For the board, it matters if "to" is occupied by nothing
	//or by the opposite player
	if(m_board[to.y][to.x].getColor() == Players::BLANK) {

		//Swap the pieces position (from becomes blank,
		//to takes on the value of the piece being moved)
		Piece temp              = m_board[to.y][to.x];
		m_board[to.y][to.x]     = pieceToMove;
		m_board[from.y][from.x] = temp;
	
	//In the other case, then it must be the opposite color
	} else {

		//Remove the piece (it has been captured)
		m_board[to.y][to.x] = pieceToMove;

		//The old position gets a blank piece
		m_board[from.x][from.y] = Piece();
	}	
}

void Board::cliShow() {

	//Loop over the m_board
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {

			//If this position is null, print #
			if(m_board[i][j].getType() == PieceTypes::NONE) {
				std::cout << " #";

			} else if(m_board[i][j].getType() == PieceTypes::PAWN) {
				std::cout << " P";

			} else if(m_board[i][j].getType() == PieceTypes::KNIGHT) {
				std::cout << " N";

			} else if(m_board[i][j].getType() == PieceTypes::BISHOP) {
				std::cout << " B";

			} else if(m_board[i][j].getType() == PieceTypes::ROOK) {
				std::cout << " R";

			} else if(m_board[i][j].getType() == PieceTypes::QUEEN) {
				std::cout << " Q";

			} else if(m_board[i][j].getType() == PieceTypes::KING) {
				std::cout << " K";

			//If we reach this, then there has been an error
			} else {
				std::cout << " !";

			} 

			//If it's the end of a row, add a new line
			if(j == 7) {
				std::cout << "\n";
			}
		}
	}
}