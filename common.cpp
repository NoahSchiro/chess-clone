#pragma once

//Represents the state of the game
enum GameState {
	NONE,
	WHITE_CHECK,
	BLACK_CHECK,
	WHITE_CHECKMATE,
	BLACK_CHECKMATE
};

//Who's turn is it
enum Players {
	WHITE,
	BLACK
};

//Enumeration of the types of pieces
enum PieceTypes {
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
};