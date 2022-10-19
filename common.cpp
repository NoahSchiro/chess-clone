#pragma once

//Represents the state of the game
enum GameState {
	WHITE_MOVE,
	BLACK_MOVE,
	WHITE_CHECK,
	BLACK_CHECK,
	WHITE_CHECKMATE,
	BLACK_CHECKMATE
};

//List of players
enum Players {
	WHITE,
	BLACK,
	BLANK
};

//Enumeration of the types of pieces
enum PieceTypes {
	NONE,
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
};
	
//Position on board
struct Coordinates {

	Coordinates() = default;

	Coordinates(unsigned int first,
				unsigned int second) {
		x = first;
		y = second;
	}

	unsigned int x;
	unsigned int y;
};