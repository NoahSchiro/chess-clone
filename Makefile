CC = g++
CFLAGS = -w -lSDL2 -lSDL2_image
OBJ = ./pieces/piece.o ./pieces/pawn.o ./pieces/knight.o ./pieces/bishop.o ./pieces/rook.o ./pieces/queen.o ./pieces/king.o board.o common.o ./graphics/SDLHandler.o
GRAPHICS = ./graphics/SDLHandler.h

%.o: %.cpp  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: main.cpp $(OBJ)

	# Compile graphics
	$(CC) $(GRAPHICS)
	
	# Compile main program
	$(CC) $^ -o chess $(CFLAGS)  

clean:
	rm *.o
	rm ./pieces/*.o
	rm ./graphics/*.o
	rm ./graphics/*.h.gch
	rm chess