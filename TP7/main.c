#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"
#include "graphics.h"

#define GRID_SCALE 75

int main(int argc, char* argv[]){
  Board B, original;
  fread_board(argv[1], B);
  fread_board(argv[1], original);

  /* Draw the base of board */
  create_window();
  draw_lines();
  draw_columns();
  draw_boardNumbers(B);
  MLV_update_window();
  /* --- */

  /* Main game loop */
  MLV_Event event = MLV_NONE;
  MLV_Keyboard_button key_button;
  MLV_Button_state mouse_state;
  int x_pixel, y_pixel, x_pos, y_pos, numberToPut, choosing=0;

  while (!(endGame(B) || key_button == MLV_KEYBOARD_ESCAPE)) { // Conditions d'arrêt du jeu

  	// On récupère les différentes informations sur le clic
	event = MLV_wait_event(
			&key_button,
			NULL,
			NULL,
			NULL,
			NULL,
			&x_pixel,
			&y_pixel,
			NULL,
			&mouse_state
		);

	if (event == MLV_MOUSE_BUTTON && mouse_state == MLV_RELEASED) {
		/* The player has pressed a button */

		/* S'il clique sur la grille du Sudoku */
		if (x_pixel<725 && x_pixel>50 && y_pixel<725 && y_pixel>50) {
			// S'il a déjà cliquer sur une case
			if (choosing==1) {
				draw_boardNumber(B, y_pos, x_pos);
			}
			x_pos = (x_pixel-50)/GRID_SCALE;
			y_pos = (y_pixel-50)/GRID_SCALE;
			printf("Mouse click on (%d,%d)\n", x_pos, y_pos);
			// On vérifie que ce n'est pas un des nombres de base présent sur la grille
			if (notInOriginalBoard(original, y_pos, x_pos)) {
				// Si la case possède déjà un nombre, on le cache
				if (B[y_pos][x_pos]!=0){
					clean_boardCase(y_pos, x_pos);
				}
				// Puis on affiche le pad des nombres et un ?
				choosing=1;
				draw_padNumber();
				char c[2] = "?\0";
				draw_onBoard(y_pos,x_pos,c);
				MLV_update_window();		
			}

		}


		/* S'il clique sur la grille de sélection de nombre */	
		if (x_pixel<1045 && x_pixel>820 && y_pixel<525 && y_pixel>300 && choosing==1) {
			// Calcul du nombre sur le pad 
			numberToPut = ((x_pixel-820)/GRID_SCALE)+1;
			numberToPut += ((y_pixel-300)/GRID_SCALE)*3;
			printf("Mouse click on %d\n", numberToPut);
			// Si c'est un nombre valide, on le place dans le Board
			if (valid_line(B, y_pos, numberToPut) && valid_column(B, x_pos, numberToPut) && valid_square(B, y_pos, x_pos, numberToPut)) { // Si légal, on met dans le Board
				B[y_pos][x_pos]=numberToPut;
				draw_boardNumber(B, y_pos, x_pos);
				choosing=0;
				clean_padNumber();
				MLV_update_window();
			}
		}
	}
  }
  /* --- */

  /* On libère la fenêtre après la fin du jeu (ou en appuyant sur échap pour quitter) */
  MLV_free_window();

  return 0;
}
