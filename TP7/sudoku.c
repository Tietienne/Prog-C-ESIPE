#include <stdio.h>

#include "sudoku.h"
#include "graphics.h"

int endGame(Board b){
	for (int i=0;i<9;i++) {
		for (int j=0;j<9;j++) {
			int nb = b[i][j];
			if (nb==0) {
				return 0;
			}
		}
	}
	return 1;
}

int notInOriginalBoard(Board original, int x, int y) {
	if (original[x][y]!=0) {
		return 0;
	}
	return 1;
}

int valid_line(Board b, int x, int number) {
	for (int i=0;i<9;i++) {
		if(b[x][i]==number) {
			return 0;
		}
	}
	return 1;
}

int valid_column(Board b, int y, int number) {
	for (int i=0;i<9;i++) {
		if(b[i][y]==number) {
			return 0;
		}
	}
	return 1;
}

int valid_square(Board b, int x, int y, int number) {
	for (int i=(x-x%3);i<(x-x%3)+3;i++) {
		for (int j=(y-y%3);j<(y-y%3)+3;j++) {
			if (b[i][j]==number) {
				return 0;
			}
		}
	}
	return 1;
}