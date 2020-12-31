#include <stdio.h>
#include <stdlib.h>

int puissance(int number, int p) { /* Fonction itérative */
  int result=number;
  for (int i=1;i<p;i++) {
    result*=number;
  }
  return result;
}

int puissanceRec(int result, int number, int p) { /* Fonction récursive */
  if (p==1) {
    return result;
  }
  return puissanceRec(result*number, number, p-1);
}

int main(int argc, char* argv[]) {
  if (argc>=3) {
    int number = atoi(argv[1]); /* On transforme les arguments en entiers */
    int p = atoi(argv[2]);

    printf("Première façon (Itérative) :\n%d^%d = %d\n", number, p, puissance(number, p));

    printf("Deuxième façon (Récursive) :\n%d^%d = %d\n", number, p, puissanceRec(number, number, p));
  } else {
    printf("Erreur : Pas assez d'arguments !\n");
  }
  return 0;
}
