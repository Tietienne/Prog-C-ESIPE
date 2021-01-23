#include <stdio.h>
#include <stdlib.h>

#define N 200000000

unsigned long int tab[N];

/* Initialisation de notre tableau de taille 200 000 000 avec des -1 */
void init_tab() {
	for (int i=0;i<N;i++) {
		tab[i]=-1;
	}
}

/* Cette fonction renvoie la longueur de vol pour un entier number */
unsigned long int syracuse(unsigned long int number) {
	unsigned long int compteur=0;
	/* printf("%d ", number); */
	if (number==1) {
		return 0;
	}

	/* On vérifie si la valeur est déjà présente dans notre tableau */
	if ((number-1)<N && tab[number-1]!=-1) {
		/* Si c'est le cas, on la renvoie et on recalcule pas sa valeur*/
		return tab[number-1];
	}
	/* Sinon, on la calcule */

	/* Suite Syracuse comme indiqué dans le TP */
	if (number%2==0) {
		compteur = 1+syracuse(number/2);
	} else {
		compteur = 1+syracuse(3*number+1);
	}

	/* Si notre nombre est compris dans notre tableau, on ajoute sa valeur de vol dedans */
	if ((number-1)<N) {
		tab[number-1]=compteur;
	}

	return compteur;
}

/* Pour les valeurs de 1 à 200 000 000, on calcule les valeurs de vols de chacun, et on renvoi le maximum */
int maximumSyracuse() {
	int max=0, valeur;
	for (int i=1;i<=N;i++) {
		valeur=syracuse(i);
		if (valeur>max) {
			max=valeur;
		}
	}
	return max;
}

int main(int argc, char* argv[]){
	init_tab();
	printf("Fly length of 27 : %ld\n", syracuse(27)); /* Test de la fonction Syracuse pour une petite valeur (valeur de vol : 111 ici)*/
	printf("Max fly : %d\n", maximumSyracuse());
	
	return 0;
}