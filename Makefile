CC = g++
CFLAGS = 
OBJ = ./pieces/piece.o board.o common.o 

%.o: %.cpp  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: main.cpp $(OBJ)
	$(CC) $^ $(CFLAGS) -o chess
	rm *.o
	rm ./pieces/piece.o

clean:
	rm chess