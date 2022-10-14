#include "board.h"
#include "./pieces/pawn.h"

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

	//CURRENTLY BROKEN WHILE I WORK ON PIECES
	//White back row
	// m_board[0][0] = Piece(rook,   white, 0, 0);
	// m_board[0][1] = Piece(knight, white, 0, 1);
	// m_board[0][2] = Piece(bishop, white, 0, 2);
	// m_board[0][3] = Piece(queen,  white, 0, 3);
	// m_board[0][4] = Piece(king,   white, 0, 4);
	// m_board[0][5] = Piece(bishop, white, 0, 5);
	// m_board[0][6] = Piece(knight, white, 0, 6);
	// m_board[0][7] = Piece(rook,   white, 0, 7);

	//White & Black pawn row
	for(int i = 0; i < 8; i++) {

		Coordinates whitePos, blackPos;
		whitePos.x = i;
		whitePos.y = 1;
		blackPos.x = i;
		blackPos.y = 6;

		m_board[1][i] = Pawn(white, whitePos);
		m_board[6][i] = Pawn(black, blackPos);
	}

	// //Black back row
	// m_board[7][0] = Piece(rook,   black, 7, 0);
	// m_board[7][1] = Piece(knight, black, 7, 1);
	// m_board[7][2] = Piece(bishop, black, 7, 2);
	// m_board[7][3] = Piece(queen,  black, 7, 3);
	// m_board[7][4] = Piece(king,   black, 7, 4);
	// m_board[7][5] = Piece(bishop, black, 7, 5);
	// m_board[7][6] = Piece(knight, black, 7, 6);
	// m_board[7][7] = Piece(rook,   black, 7, 7);
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