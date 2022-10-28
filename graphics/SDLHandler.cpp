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

	//Make the surface of the window black
	m_screenSurface = SDL_GetWindowSurface(m_window);
	SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0x00, 0x00, 0x00));
	SDL_UpdateWindowSurface(m_window);

	//Next we set up the renderer
	m_renderer =  SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDLHandler::~SDLHandler() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLHandler::update() {

	//Clear drawing surface
	SDL_RenderClear(m_renderer);
    
    //Rectangle we will draw for the
    SDL_Rect rect;
    rect.x = 0; //X position
    rect.y = 0; //Y position
    rect.w = m_tileSide; //Width
    rect.h = m_tileSide; //Height

    //Top left is always going to be the lighter color
    for(int y = 0; y < 8; y++) {
    	for (int x = 0; x < 8; x++) {

    		//This if block just controls for the
    		//alternating lightness and darkness 
    		//of the board
    		if((y % 2 == 0 && x % 2 == 0 )||
    		   (y % 2 == 1 && x % 2 == 1)) {

			    //Drawing in "light brown ish"
			    //TODO: make this look less ugly
			    SDL_SetRenderDrawColor(m_renderer, 171, 101, 29, 1);
			    
			    //Draw the rectangle
			    SDL_RenderFillRect(m_renderer, &rect);    			

    		} else {

			    //Drawing in "dark brown ish"
			    //TODO: make this look less ugly
			    SDL_SetRenderDrawColor(m_renderer, 91, 67, 33, 1);
			    
			    //Draw the rectangle
			    SDL_RenderFillRect(m_renderer, &rect);
    		}

    		//At each step, we need to increment to the next drawing position

    		rect.x += m_tileSide;
    	}
    	rect.x = 0;
    	rect.y += m_tileSide;
    }

    //Show
    SDL_RenderPresent(m_renderer);
}