CC = g++
CFLAGS = 
OBJ = ./pieces/piece.o ./pieces/pawn.o ./pieces/knight.o ./pieces/bishop.o ./pieces/rook.o ./pieces/queen.o ./pieces/king.o board.o common.o 

%.o: %.cpp  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: main.cpp $(OBJ)
	$(CC) $^ $(CFLAGS) -o chess
	rm *.o
	rm ./pieces/*.o

clean:
	rm chess