#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  int entier1=0;
  int entier2=0;

  /*  printf("Premier entier : ");
    scanf("%d", &entier1);
    printf("Deuxième entier : ");
    scanf("%d", &entier2);
  */

  if (argc>=3) { /* S'il y a assez d'arguments, on les convertit en entier puis on affiche la somme */
    entier1=atoi(argv[1]);
    entier2=atoi(argv[2]);
    int somme = entier1 + entier2;

    printf("%d + %d = %d\n",entier1, entier2, somme);
  } else {
    printf("Pas assez d'arguments");
  }

  return 0;
}
