#include "SDLHandler.h"

#include <SDL2/SDL_image.h>
#include <iostream>

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
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void SDLHandler::update(Piece* board[8][8]) {

	//Clear drawing surface
	SDL_RenderClear(m_renderer);
    
    //Rectangle we will draw for the
    SDL_Rect rect;
    rect.x = 0; //X position
    rect.y = 0; //Y position
    rect.w = m_tileSide; //Width
    rect.h = m_tileSide; //Height

    //Loop through the "board" and create the tile.
    //Note the top left will be the lighter of the
    //two colors
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



    //Define the dimensions of the image
    SDL_Rect textureRect;
    textureRect.x = 10;
    textureRect.y = 10;
    textureRect.w = 100;
    textureRect.h = 100;

    //Next lets draw the pieces according to
    //the board layout that has been passed in
    for(int y = 0; y < 8; y++) {
    	for (int x = 0; x < 8; x++) {

    		//Store since we will use this a lot
    		Piece* temp = board[y][x];

    		    //This is a standard "image" which will be adapted according to what we want to draw
    			SDL_Texture* img = NULL;

    		//If the piece is white
    		if(temp->getColor() == Players::WHITE) {

    			if(temp->getType() == PieceTypes::PAWN) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Pawn_Light.bmp");

    			} else if (temp->getType() == PieceTypes::KNIGHT) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Knight_Light.bmp");

    			} else if (temp->getType() == PieceTypes::BISHOP) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Bishop_Light.bmp");

    			} else if (temp->getType() == PieceTypes::ROOK) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Rook_Light.bmp");

    			} else if (temp->getType() == PieceTypes::QUEEN) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Queen_Light.bmp");

    			} else if (temp->getType() == PieceTypes::KING) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/King_Light.bmp");
    			}

    		//Black pieces
    		} else if (temp->getColor() == Players::BLACK) {

    			if(temp->getType() == PieceTypes::PAWN) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Pawn_Dark.bmp");

    			} else if (temp->getType() == PieceTypes::KNIGHT) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Knight_Dark.bmp");

    			} else if (temp->getType() == PieceTypes::BISHOP) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Bishop_Dark.bmp");

    			} else if (temp->getType() == PieceTypes::ROOK) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Rook_Dark.bmp");

    			} else if (temp->getType() == PieceTypes::QUEEN) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/Queen_Dark.bmp");

    			} else if (temp->getType() == PieceTypes::KING) {
				    img = IMG_LoadTexture(m_renderer, "./graphics/piecesBMP/King_Dark.bmp");
    			}
    		}

    		//Only add the texture to the render IF it's not a blank image
    		if(temp->getColor() != Players::BLANK) {
			    SDL_RenderCopy(m_renderer, img, NULL, &textureRect);
    		}

    		//No matter what, we want to increment to the next drawing area
    		textureRect.x += m_tileSide;
    	}

    	//Increment down to the next row
    	textureRect.x = 10;
    	textureRect.y += m_tileSide;
    }

    //Show
    SDL_RenderPresent(m_renderer);
}