CC = gcc
CFLAGS =
OBJ = ./pieces/piece.o board.o common.o 

%.o: %.c  %.h
	$(CC) -c -o $@ $< $(CFLAGS)

chess: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	rm *.o

clean:
	rm chess