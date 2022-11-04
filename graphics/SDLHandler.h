#include <SDL2/SDL.h>

#include "../common.cpp"
#include "../board.h"

class SDLHandler {
public:

	//Init and other stuff
	SDLHandler();
	~SDLHandler();

	void update(Piece* board[8][8]);

private:

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;
	SDL_Surface* m_screenSurface = NULL;

	//Window dimensions
	int m_width  = 1920;
	int m_height = 1000;

	//Tile dimensions (tiles are square, 
	//so we need side length)
	int m_tileSide = 120;

};