#include <iostream>

#include "./graphics/SDLHandler.h"
#include "board.h"

int main(int, char **) {

	SDLHandler myHandler;

	myHandler.update();

	SDL_Delay(5 * 1000);

	return 0;
}