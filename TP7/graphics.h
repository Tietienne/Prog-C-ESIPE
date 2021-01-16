#ifndef __GRAPHICS__
#define __GRAPHICS__

#include <MLV/MLV_all.h>
#include "sudoku.h"

void create_window();
void draw_lines();
void draw_columns();
void draw_padNumber();
void draw_boardNumbers(Board b);
void draw_onBoard(int line, int column, char* c);
void clean_boardCase(int line, int column);
void clean_padNumber();
void draw_boardNumber(Board b, int i, int j);

#endif