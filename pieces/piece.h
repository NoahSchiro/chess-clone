#pragma once

#include "../common.cpp"

#include <vector>

//Forward declare board to avoid circular dependency
class Board;

/*
Base class to represent a chess piece.
Unlikely to be used directly
*/
class Piece {
public:

	//Null constructor
	Piece() = default;
	~Piece() = default;

	Piece(PieceTypes  type,
		  Players     color,
		  Coordinates position);

	//Given the pieces position, what are the valid moves?
	virtual std::vector<Coordinates> generateValidMoves();

	//Getters
	PieceTypes getType();
	Players getColor();
	Coordinates getPosition();
	virtual bool getFirstMove();

	//Setters
	void setType(PieceTypes input);
	void setColor(Players input);
	void setPosition(Coordinates input);
	virtual void setFirstMove(bool input);

protected:

	//What piece is this specifically?
	PieceTypes  m_type;

	//What side is this piece on
	Players     m_color;

	//Location
	Coordinates m_position;
};