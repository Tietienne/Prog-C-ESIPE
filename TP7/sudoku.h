#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

int endGame(Board b);
int notInOriginalBoard(Board original, int x, int y);
int valid_line(Board b, int x, int number);
int valid_column(Board b, int y, int number);
int valid_square(Board b, int x, int y, int number);

#endif
