#include <SDL2/SDL.h>

class SDLHandler {
public:

	//Init and other stuff
	SDLHandler();
	~SDLHandler();

	void update();

private:

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_renderer = NULL;
	SDL_Surface* m_screenSurface = NULL;

	int m_width  = 1920;
	int m_height = 1080;
};