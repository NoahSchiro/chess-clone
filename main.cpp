#include <iostream>

#include "./graphics/SDLHandler.h"
#include "board.h"

int main(int, char **) {

	Board myBoard;

	SDLHandler myHandler;

	myHandler.update(myBoard.m_board);

	SDL_Delay(6 * 1000);

	return 0;
}