#include <stdio.h>
#include <string.h>

void wc(char *sentence){
  char c;
  int n = 0, word = 0, line = 0; /* n est le nombre de caractères */
  c = sentence[n];

  while (sentence!=NULL) { /* On parcourt toute la phrase caractère par caractère */
    switch (c) {
      case '\n': line++; break; /* Dès qu'on croise un retour à la ligne, on comptabile une ligne */
      case ' ' : word++; break; /* De meme avec les espaces et tabulations pour le nombre de mots */
    }
    n+=1;
    c = sentence[n];
  }
  printf("Nombre de caractères : %d\nNombre de mots : %d\nNombre de lignes : %d\n", n, word, line);
}

int main(int argc, char* argv[]) {
  char* sentence[];

  printf("Ecrivez un texte, nous compterons le nombre de caractères, mots et lignes : ");
  scanf("%s", &sentence);
  int len = strlen(sentence);
  printf("%d", len);
  for (int i=0; i < len; i++) {
    printf("%c", sentence[i]);
  }

  /*wc(sentence);*/

  return 0;
}
