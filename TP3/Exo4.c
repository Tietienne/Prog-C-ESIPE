#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

int rec_dichotomique(int tableau[], int valeur, int borne_inf, int borne_sup) {
	int num_milieu = (borne_inf+borne_sup)/2;
	int val_milieu = tableau[num_milieu];
	if (val_milieu==valeur) {
		return num_milieu+1;
	}

	if (num_milieu==borne_inf || num_milieu==borne_sup) {
		return -1;
	}

	if (val_milieu < valeur) {
		return rec_dichotomique(tableau, valeur, num_milieu, borne_sup);
	} else {
		return rec_dichotomique(tableau, valeur, borne_inf, num_milieu);
	}
}

int main(int argc, char* argv[]) {
	int tableau[N] = {0, 0, 1, 2, 4, 6, 7, 9, 20, 29};
	int valeur = 20;

	int result = rec_dichotomique(tableau, valeur, 0, N);

	printf("Le tableau est le suivant :\n[");

	for (int i=0; i<N; i++) {
		if (i==N-1) {
			printf("%d", tableau[i]);
		} else {
			printf("%d, ",tableau[i]);
		}
	}

	printf("]\nPosition de la valeur %d dans le tableau : %d\n", valeur, result);

	return 0;
}