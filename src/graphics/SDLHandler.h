#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../common.cpp"
#include "../board.h"

class SDLHandler {
public:

	//Init and other stuff
	SDLHandler();
	~SDLHandler();

	void drawBackground(std::vector<Coordinates> validMoves);

	void update(Piece* board[8][8], std::vector<Coordinates> validMoves, Players perspective);

	void clickHandler(int &x, int &y, Players perspective);

private:

	SDL_Window*   m_window = NULL;
	SDL_Renderer* m_renderer = NULL;
	SDL_Surface*  m_screenSurface = NULL;

	//Window dimensions
	int m_width  = 1920;
	int m_height = 1000;

	//Tile dimensions (tiles are square, 
	//so we need side length)
	int m_tileSide = 120;

	//Image asset holders
	SDL_Texture* m_whitePawn   = NULL;
	SDL_Texture* m_blackPawn   = NULL;
	SDL_Texture* m_whiteKnight = NULL;
	SDL_Texture* m_blackKnight = NULL;
	SDL_Texture* m_whiteBishop = NULL;
	SDL_Texture* m_blackBishop = NULL;
	SDL_Texture* m_whiteRook   = NULL;
	SDL_Texture* m_blackRook   = NULL;
	SDL_Texture* m_whiteQueen  = NULL;
	SDL_Texture* m_blackQueen  = NULL;
	SDL_Texture* m_whiteKing   = NULL;
	SDL_Texture* m_blackKing   = NULL;

};