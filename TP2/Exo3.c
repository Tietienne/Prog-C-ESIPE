#include <stdio.h>
#include <stdlib.h>

void printNumbers(int number) { /* Fonction Itérative */
  for (int i=number;i>=1;i--) { /* Première boucle qui print de number à 1 */
    printf("%d ",i);
  }
  for (int j=1;j<=number;j++) { /* Deuxième boucle qui print de 1 à number */
    if (j==number) {
      printf("%d\n", j); /* Ce printf est le dernier effectué avec un retour à la ligne */
    } else {
      printf("%d ", j);
    }
  }
}

void printRecNumbers(int number, int initialNumber) { /* Fonction Récursive */
  if (number==0) { /* Condition d'arrêt de la fonction récursive */
    return;
  }
  printf("%d ", number); /* Affichage de number à 1 */
  printRecNumbers(number-1, initialNumber);
  if (number == initialNumber) {
    printf("%d\n", number); /* Affichage de number (le dernier) avec un retour à la ligne */
  } else {
    printf("%d ", number); /* Affichage de 1 à number-1 */
  }
}

int main(int argc, char* argv[]) {
  int number = 0;

  if (argc>=2) {
    number = atoi(argv[1]); /* On convertit le 1er argument en entier */
  }

  printf("Première façon (Itérative) :\n");
  printNumbers(number);

  printf("Deuxième façon (Récursive) :\n");
  printRecNumbers(number, number);

  return 0;
}
