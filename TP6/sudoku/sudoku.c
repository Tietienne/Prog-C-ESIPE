#include <stdio.h>

#include "sudoku.h"

void initialize_empty_board(Board grid){

}

void print_board(Board grid){
	for(int i=0;i<9;i++) {
		printf("-------------------------------------\n");
		for (int j=0;j<9;j++) {
			int nb = grid[i][j];
			if (nb!=0) {
				printf("| %d ", nb);
			} else {
				printf("|   ");
			}
		}
		printf("|\n");
	}
	printf("-------------------------------------\n");
}

int is_line_correct(Board grid) {
	return 0;
}

int is_column_correct(Board grid) {
	return 0;
}

int is_square_correct(Board grid) {
	return 0;
}

void resolve_board_rec(Board grid, int current, int max) {
	
}

void resolve_board(Board grid) {
	for (int i=0;i<9;i++) {
		for (int j=0; j<9;j++) {
			if (grid[i][j]==0) {

			}
		}
	}
}



/*
void permutations(int buffer[], int current, int max) {
	if (current>max) {
		print_array(buffer, max);
		return;
	}

	for (int i=0;i<max;i++) {
		if (buffer[i]==0) {
			buffer[i]=current;
			permutations(buffer, current+1, max);
			buffer[i]=0;
		}
	}
}*/