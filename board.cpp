#include "board.h"

//Constructor
Board::Board() {

	//The board always has the same configuration at the beginning
	m_state = GameState::NONE;
	m_turn  = Players::WHITE;

	//Temp variables to make our lives easier
	Players white = Players::WHITE;
	Players black = Players::BLACK;

	PieceTypes pawn   = PieceTypes::PAWN;
	PieceTypes bishop = PieceTypes::BISHOP;
	PieceTypes knight = PieceTypes::KNIGHT;
	PieceTypes rook   = PieceTypes::ROOK;
	PieceTypes queen  = PieceTypes::QUEEN;
	PieceTypes king   = PieceTypes::KING;

	//White back row
	m_board[0][0] = Piece(rook,   white, 0, 0);
	m_board[0][1] = Piece(knight, white, 0, 1);
	m_board[0][2] = Piece(bishop, white, 0, 2);
	m_board[0][3] = Piece(queen,  white, 0, 3);
	m_board[0][4] = Piece(king,   white, 0, 4);
	m_board[0][5] = Piece(bishop, white, 0, 5);
	m_board[0][6] = Piece(knight, white, 0, 6);
	m_board[0][7] = Piece(rook,   white, 0, 7);

	//White & Black pawn row
	for(int i = 0; i < 8; i++) {
		m_board[1][i] = Piece(pawn, white, 1, i);
		m_board[6][i] = Piece(pawn, black, 6, i);
	}

	//Black back row
	m_board[7][0] = Piece(rook,   black, 7, 0);
	m_board[7][1] = Piece(knight, black, 7, 1);
	m_board[7][2] = Piece(bishop, black, 7, 2);
	m_board[7][3] = Piece(queen,  black, 7, 3);
	m_board[7][4] = Piece(king,   black, 7, 4);
	m_board[7][5] = Piece(bishop, black, 7, 5);
	m_board[7][6] = Piece(knight, black, 7, 6);
	m_board[7][7] = Piece(rook,   black, 7, 7);
}

void Board::cliShow() {

}