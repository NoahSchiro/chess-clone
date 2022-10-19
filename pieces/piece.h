#pragma once

#include "../common.cpp"

#include <vector>

/*
Base class to represent a chess piece.
Unlikely to be used directly
*/
class Piece {
public:

	//Null constructor
	Piece() = default;

	Piece(PieceTypes  type,
		  Players     color,
		  Coordinates position);


	//Getters
	PieceTypes getType();
	Players getColor();
	Coordinates getPosition();

	//Setters
	void setType(PieceTypes input);
	void setColor(Players input);
	void setPosition(Coordinates input);

	//Given the pieces position, what are the valid moves?
	std::vector<Coordinates> generateValidMoves();

private:

	//What piece is this specifically?
	PieceTypes  m_type;

	//What side is this piece on
	Players     m_color;

	//Location
	Coordinates m_position;
};