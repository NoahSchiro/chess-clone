CC = g++
CFLAGS = -w -lSDL2
OBJ = ./pieces/piece.o ./pieces/pawn.o ./pieces/knight.o ./pieces/bishop.o ./pieces/rook.o ./pieces/queen.o ./pieces/king.o board.o common.o ./graphics/SDLHandler.o
GRAPHICS = ./graphics/SDLHandler.h

%.o: %.cpp  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: main.cpp $(OBJ)

	# Compile graphics
	$(CC) $(GRAPHICS)
	
	# Compile main program
	$(CC) $^ -o chess $(CFLAGS)  
	rm *.o
	rm ./pieces/*.o
	rm ./pieces/*.gch

clean:
	rm chess