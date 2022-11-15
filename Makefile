CC = g++
CFLAGS = -w -lSDL2 -lSDL2_image
OBJ = ./src/pieces/piece.o ./src/pieces/pawn.o ./src/pieces/knight.o ./src/pieces/bishop.o ./src/pieces/rook.o ./src/pieces/queen.o ./src/pieces/king.o ./src/board.o ./src/common.o ./src/graphics/SDLHandler.o
GRAPHICS = ./src/graphics/SDLHandler.h

%.o: %.cpp  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: ./src/main.cpp $(OBJ)

	# Compile graphics
	$(CC) $(GRAPHICS)
	
	# Compile main program
	$(CC) $^ -o chess $(CFLAGS)  

clean:
	find . -type f -name '*.o' -delete
	rm ./src/graphics/*.h.gch
	rm chess