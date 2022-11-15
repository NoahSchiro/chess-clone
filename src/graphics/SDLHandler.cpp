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

	if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		fprintf(stderr, "could not init images: %s\n", SDL_GetError());
		return;
	}

	//Make the surface of the window black
	m_screenSurface = SDL_GetWindowSurface(m_window);
	SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0x00, 0x00, 0x00));
	SDL_UpdateWindowSurface(m_window);

	//Next we set up the renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	//Load in the image assets
	m_whitePawn   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Pawn_Light.bmp");
	m_blackPawn   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Pawn_Dark.bmp");
	m_whiteKnight = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Knight_Light.bmp");
	m_blackKnight = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Knight_Dark.bmp");
	m_whiteBishop = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Bishop_Light.bmp");
	m_blackBishop = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Bishop_Dark.bmp");
	m_whiteRook   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Rook_Light.bmp");
	m_blackRook   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Rook_Dark.bmp");
	m_whiteQueen  = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Queen_Light.bmp");
	m_blackQueen  = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/Queen_Dark.bmp");
	m_whiteKing   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/King_Light.bmp");
	m_blackKing   = IMG_LoadTexture(m_renderer, "./assets/piecesBMP/King_Dark.bmp");

}

SDLHandler::~SDLHandler() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

//Piece* board - the current state of the board
//int x        - the x position of a mouse click
void SDLHandler::update(Piece* board[8][8], std::vector<Coordinates> validMoves) {

	//We will clear the screen to black
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 1);

	//Clear drawing surface
	SDL_RenderClear(m_renderer);

    //Rectangle we will draw with
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

    		//Flag to check if we want to color
    		//this space we can move to 
    		bool validMoveArea = false;

    		//Check if our coordinate is in the valid moves
    		for(int i = 0; i < validMoves.size(); i++) {
    			if(validMoves[i].x == x && validMoves[i].y == y) {
    				validMoveArea = true;
    				validMoves.erase(validMoves.begin() + i);
    			}
    		}

    		//This if statement just generates that checkboard look
    		//by making sure two adjacent squares don't have the same color
    		if ((y % 2 == 0 && x % 2 == 0)||
    		    (y % 2 == 1 && x % 2 == 1)) {

			    //Drawing in "light brown ish"
			    //TODO: make this look less ugly
			    SDL_SetRenderDrawColor(m_renderer, 171, 101, 29, 1);

				//If we have selected a piece and want to
				//show where it can move, then display a "light red"
				if(validMoveArea) {
				    SDL_SetRenderDrawColor(m_renderer, 221, 91, 29, 1);
				}
			    
    		} else {

			    //Drawing in "dark brown ish"
			    //TODO: make this look less ugly
			    SDL_SetRenderDrawColor(m_renderer, 91, 67, 33, 1);
			    
			    //If we have selected a piece and want to
				//show where it can move, then display a "light red"
				if(validMoveArea) {
				    SDL_SetRenderDrawColor(m_renderer, 141, 57, 33, 1);
				}
    		}

		    //Draw the rectangle
		    SDL_RenderFillRect(m_renderer, &rect);

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

    //This is a standard "image" which will be adapted according to what we want to draw
	SDL_Texture* img = NULL;

    //Next lets draw the pieces according to
    //the board layout that has been passed in
    for(int y = 0; y < 8; y++) {
    	for (int x = 0; x < 8; x++) {

    		//Store since we will use this a lot
    		Piece* temp = board[y][x];

    		//If the piece is white
    		if(temp->getColor() == Players::WHITE) {

    			if(temp->getType() == PieceTypes::PAWN) {
				    img = m_whitePawn;

    			} else if (temp->getType() == PieceTypes::KNIGHT) {
				    img = m_whiteKnight;

    			} else if (temp->getType() == PieceTypes::BISHOP) {
				    img = m_whiteBishop;

    			} else if (temp->getType() == PieceTypes::ROOK) {
				    img = m_whiteRook;

    			} else if (temp->getType() == PieceTypes::QUEEN) {
				    img = m_whiteQueen;

    			} else if (temp->getType() == PieceTypes::KING) {
				    img = m_whiteKing;
    			}

    		//Black pieces
    		} else if (temp->getColor() == Players::BLACK) {

    			if(temp->getType() == PieceTypes::PAWN) {
				    img = m_blackPawn;

    			} else if (temp->getType() == PieceTypes::KNIGHT) {
				    img = m_blackKnight;

    			} else if (temp->getType() == PieceTypes::BISHOP) {
				    img = m_blackBishop;

    			} else if (temp->getType() == PieceTypes::ROOK) {
				    img = m_blackRook;

    			} else if (temp->getType() == PieceTypes::QUEEN) {
				    img = m_blackQueen;

    			} else if (temp->getType() == PieceTypes::KING) {
				    img = m_blackKing;
    			}
    		}

    		//Only add the texture to the render IF it's not a blank image
    		if(temp->getColor() != Players::BLANK) {

			    SDL_RenderCopy(m_renderer, img, nullptr, &textureRect);
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

    //Free up this resource
    img = NULL;
    SDL_DestroyTexture(img);
}

void SDLHandler::clickHandler(int &x, int &y) {

	//Holds the coordinates of the mouse position
	uint32_t buttons;

	//Fetch the mouse position
	SDL_GetMouseState(&x, &y);

	//Convert to board position
	//Recall that tiles are 120px square
	x /= 120;
	y /= 120;

	//If we click outside of the board area, then ignore
	if(x > 7 || y > 7) {
		return;
	}

}
