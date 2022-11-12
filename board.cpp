#include "board.h"

#include "./pieces/pawn.h"
#include "./pieces/knight.h"
#include "./pieces/bishop.h"
#include "./pieces/rook.h"
#include "./pieces/queen.h"
#include "./pieces/king.h"


#include <stdlib.h>
#include <iostream>

//Constructor
Board::Board() {

	//The board always has the same configuration 
	//at the beginning. White moves
	m_state = GameState::WHITE_MOVE;

	//Temp variables to make our lives easier
	Players white = Players::WHITE;
	Players black = Players::BLACK;

	//I will make one coordinate structure to modify for each item
	Coordinates pos(0, 0);

	//White back row
	m_board[0][0] = new Rook(white, pos);

	pos.x = 1;
	m_board[0][1] = new Knight(white, pos);
	
	pos.x = 2;
	m_board[0][2] = new Bishop(white, pos);

	pos.x = 3;
	m_board[0][3] = new King(white, pos);
	
	pos.x = 4;
	m_board[0][4] = new Queen(white, pos);

	pos.x = 5;
	m_board[0][5] = new Bishop(white, pos);

	pos.x = 6;
	m_board[0][6] = new Knight(white, pos);

	pos.x = 7;
	m_board[0][7] = new Rook(white, pos);

	//White & Black pawn row
	for(int i = 0; i < 8; i++) {

		Coordinates whitePos(i, 1);
		Coordinates blackPos(i, 6);

		m_board[1][i] = new Pawn(white, whitePos);
		m_board[6][i] = new Pawn(black, blackPos);
	}

	//For the black back row, the y position is 7
	pos.y = 7;

	//Black back row
	m_board[7][0] = new Rook(black, pos);

	pos.x = 1;
	m_board[7][1] = new Knight(black, pos);

	pos.x = 2;
	m_board[7][2] = new Bishop(black, pos);

	pos.x = 3;
	m_board[7][3] = new King(black, pos);
	
	pos.x = 4;
	m_board[7][4] = new Queen(black, pos);

	pos.x = 5;
	m_board[7][5] = new Bishop(black, pos);

	pos.x = 6;
	m_board[7][6] = new Knight(black, pos);

	pos.x = 7;
	m_board[7][7] = new Rook(black, pos);

	//For every other position, it's just a blank piece
	for(int i = 2; i < 6; i++) {
		for(int j = 0; j < 8; j++) {
			
			pos.x = j;
			pos.y = i;
			m_board[i][j] = new Piece(PieceTypes::NONE, Players::BLANK, pos);
		}
	}
}

void Board::movePiece(Coordinates from,
			          Coordinates to) {

	//Ensure valid coordinates
	if(from.x > 7 || from.y < 0 ||
	   to.x   > 7 || to.y   < 0) {
		return;
	}

	//We will need this several times
	Piece* pieceToMove = m_board[from.y][from.x];

	//Ensure there is a piece at the "from" coordinate
	if(pieceToMove->getType() == PieceTypes::NONE) {
		std::cout << "Error [Board][movePiece]: Trying to move an object from invalid position!\n";
		return;
	}

	//If the piece is the pawn, then we need to indicate that it has been moved already
	if(pieceToMove->getType() == PieceTypes::PAWN) {
		pieceToMove->setFirstMove(false);
	}

	//The piece cannot move to a position which is
	//already occupied, unless that position is
	//of the other color

	//For the position we want to move to, is it the same color as
	//the piece we are trying to move?
	if(m_board[to.y][to.x]->getColor() == pieceToMove->getColor()) {
		std::cout << "Error [Board][movePiece]: Trying to move piece into teammate!\n";
		return;
	}

	//No matter what, the piece itself only needs to
	//know where it is now
	pieceToMove->setPosition(to);

	bool isCastle = false;

	//If we are trying to castle
	if(m_board[from.y][from.x]->getType() == PieceTypes::KING &&
	   abs(from.x - to.x) > 1) { isCastle = true; }

	//For the board, it matters if "to" is occupied by nothing
	//or by the opposite player
	if(m_board[to.y][to.x]->getColor() == Players::BLANK) {

		//Swap the pieces position (from becomes blank,
		//to takes on the value of the piece being moved)
		Piece* temp             = m_board[to.y][to.x];
		m_board[to.y][to.x]     = pieceToMove;
		m_board[from.y][from.x] = temp;

		//If it's a castle then we need to handle that as well
		if(isCastle) {

			Piece* rook;
			Piece* blankSpot;
			Coordinates rookPos;

			//King side white
			if(to.x == 1 && to.y == 0) {
				
				//Set it's internal position
				rookPos.x = 2;
				rookPos.y = 0;

				//Get rook
				rook      = m_board[0][0];
				blankSpot = m_board[rookPos.y][rookPos.x];

				//Set it's external position
				m_board[rookPos.y][rookPos.x] = rook;
				m_board[0][0]                 = blankSpot;

			//King side black
			} else if (to.x == 1 && to.y == 7) {
	
				//Set it's internal position
				rookPos.x = 2;
				rookPos.y = 7;

				//Get rook
				rook      = m_board[7][0];
				blankSpot = m_board[rookPos.y][rookPos.x];

				//Set it's external position
				m_board[rookPos.y][rookPos.x] = rook;
				m_board[7][0]                 = blankSpot;

			//Queen side white
			} else if (to.x == 5 && to.y == 0) {
	
				//Set it's internal position
				rookPos.x = 4;
				rookPos.y = 0;

				//Get rook
				rook      = m_board[0][7];
				blankSpot = m_board[rookPos.y][rookPos.x];

				//Set it's external position
				m_board[rookPos.y][rookPos.x] = rook;
				m_board[0][7]                 = blankSpot;			
	
			//Queen side black
			} else if (to.x == 5 && to.y == 7) {
	
				//Set it's internal position
				rookPos.x = 4;
				rookPos.y = 7;

				//Get rook
				rook      = m_board[7][7];
				blankSpot = m_board[rookPos.y][rookPos.x];

				//Set it's external position
				m_board[rookPos.y][rookPos.x] = rook;
				m_board[7][7]                 = blankSpot;				
			}
			
			rook->setPosition(rookPos);
		}
	
	//In the other case, then it must be the opposite color
	} else {

		//The old position gets a new blank piece
		m_board[from.y][from.x] = new Piece(PieceTypes::NONE, Players::BLANK, from);
		
		//Move the piece to the captured position
		m_board[to.y][to.x] = pieceToMove;
	}	
}

void Board::cliShow() {

	//This just prints the coordinate system (x axis labels)
	std::cout << "  ";
	for(int i = 0; i < 8; i++) {
		std::cout << " " << i;
	}
	std::cout << " x\n";

	//Loop over the m_board
	for(int i = 0; i < 8; i++) {

		//Prints the labels for the y axis
		std::cout << " " << i;

		for(int j = 0; j < 8; j++) {

			//If this position is null, print #
			if(m_board[i][j]->getType() == PieceTypes::NONE) {
				std::cout << " #";

			} else if(m_board[i][j]->getType() == PieceTypes::PAWN) {
				std::cout << " P";

			} else if(m_board[i][j]->getType() == PieceTypes::KNIGHT) {
				std::cout << " N";

			} else if(m_board[i][j]->getType() == PieceTypes::BISHOP) {
				std::cout << " B";

			} else if(m_board[i][j]->getType() == PieceTypes::ROOK) {
				std::cout << " R";

			} else if(m_board[i][j]->getType() == PieceTypes::QUEEN) {
				std::cout << " Q";

			} else if(m_board[i][j]->getType() == PieceTypes::KING) {
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

	//Show that this is the y axis
	std::cout << " y\n";
}