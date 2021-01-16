#include "graphics.h"
#include "sudoku.h"
#include <stdlib.h>

void create_window(){
	/* Create the window */
	MLV_create_window("Draw", "Draw", 1200, 800);
	MLV_draw_filled_rectangle(0, 0, 1199, 799, MLV_COLOR_BLACK);
}

void draw_lines_rec(int n){
	if (n>9) {
		return;
	}
	if (n%3==0) {
		MLV_draw_line(50, 50+n*75, 50+9*75, 50+n*75, MLV_rgba(205,92,92,255));
	} else {
		MLV_draw_line(50, 50+n*75, 50+9*75, 50+n*75, MLV_COLOR_WHITE);
	}
	draw_lines_rec(n+1);
}

void draw_lines(){
	draw_lines_rec(0);
}

void draw_columns_rec(int n){
	if (n>9) {
		return;
	}

	if (n%3==0) {
		MLV_draw_line(50+n*75, 50, 50+n*75, 50+9*75, MLV_rgba(205,92,92,255));
	} else {
		MLV_draw_line(50+n*75, 50, 50+n*75, 50+9*75, MLV_COLOR_WHITE);
	}
	
	draw_columns_rec(n+1);
}

void draw_columns(){
	draw_columns_rec(0);
}

void clean_padNumber() {
	MLV_draw_filled_rectangle(800,280,250,250,MLV_COLOR_BLACK);
}

void draw_padNumber(){
	/* Draw lines */
	for (int l=0;l<4;l++) {
		MLV_draw_line(820, 300+l*75, 1045, 300+l*75, MLV_COLOR_WHITE);
	}

	/* Draw columns */
	for(int c=0;c<4;c++) {
		MLV_draw_line(820+c*75, 300, 820+c*75, 525, MLV_COLOR_WHITE);
	}

	/* Draw numbers */
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			int number = 3*i+j+1;
			char c[2];
			sprintf(c, "%d", number);
			MLV_draw_text(855+j*75,335+i*75,c,MLV_COLOR_WHITE);
		}
	}
}

void draw_onBoard(int line, int column, char* c){
	MLV_draw_text(85+column*75,85+line*75,c,MLV_COLOR_WHITE);
}

void draw_onBoardRed(int line, int column, char* c){
	MLV_draw_text(85+column*75,85+line*75,c,MLV_rgba(205,92,92,255));
}

void clean_boardCase(int line, int column){
	MLV_draw_filled_rectangle(60+column*75,60+line*75,50,50,MLV_COLOR_BLACK);
}

void draw_boardNumber(Board b, int i, int j) {
	int nb = b[i][j];
	clean_boardCase(i,j);
	if (nb!=0) {
		char c[2];
		sprintf(c, "%d", nb);
		draw_onBoard(i,j,c);
	}
}

void draw_boardNumberRed(Board b, int i, int j) {
	int nb = b[i][j];
	clean_boardCase(i,j);
	if (nb!=0) {
		char c[2];
		sprintf(c, "%d", nb);
		draw_onBoardRed(i,j,c);
	}
}

void draw_boardNumbers(Board b) {
	for (int i=0;i<9;i++) {
		for (int j=0;j<9;j++) {
			draw_boardNumberRed(b, i, j);
		}
	}
}
