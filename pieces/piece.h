#pragma once

#include "../common.cpp"

/*
Base class to represent a chess piece.
Unlikely to be used directly
*/
class Piece {
public:

	Piece(PieceTypes type,
		  Players color,
		  unsigned int locX,
		  unsigned int locY);

	//Tells us what type of piece this 
	//is. Knight, queen, pawn, etc.
	//virtual char getType() = 0;

	//Todo: Delete, this will be in derived classes
	PieceTypes m_type;
	Players m_player;
private:

	unsigned int m_locX;
	unsigned int m_locY;

};