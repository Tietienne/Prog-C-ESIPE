CC=gcc
CFLAGS=-Wall -ansi -std=c99 -lMLV
LDFLAGS=
OBJ=sudoku.o main.o in_out.o graphics.o

sudoku: $(OBJ)
	$(CC) -o sudoku $(OBJ) $(CFLAGS)

main.o: main.c sudoku.h in_out.h graphics.h
	$(CC) -c main.c $(CFLAGS)

sudoku.o: sudoku.c sudoku.h
	$(CC) -c sudoku.c $(CFLAGS)

in_out.o: in_out.c in_out.h
	$(CC) -c in_out.c $(CFLAGS)

graphics.o: graphics.c graphics.h
	$(CC) -c graphics.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f sudoku
