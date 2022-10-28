#include "SDLHandler.h"

SDLHandler::SDLHandler() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
		return;
	}
	m_window = SDL_CreateWindow(
			    "hello_sdl2",
			    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			    m_width, m_height,
			    SDL_WINDOW_SHOWN);
	
	if (m_window == NULL) {
		fprintf(stderr, "could not create window: %s\n", SDL_GetError());
		return;
	}

	m_screenSurface = SDL_GetWindowSurface(m_window);
	SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(m_window);
}

SDLHandler::~SDLHandler() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLHandler::update() {

	m_screenSurface = SDL_GetWindowSurface(m_window);
	
	SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(m_window);
}