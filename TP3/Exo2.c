#include <stdio.h>
#include <string.h>

void wc(char *sentence){
  char c;
  int n = 0, character=0, word = 0, line = 0; /* n est le nombre de caractères */
  c = sentence[n];

  while (c!='\0') { /* On parcourt toute la phrase caractère par caractère */
    switch (c) {
      case '\n': line++; break; /* Dès qu'on croise un retour à la ligne, on comptabilise une ligne */
      case ' ' : if(sentence[n+1]!=' ' && sentence[n+1]!='\n'){word++;} break; /* De meme avec les espaces et tabulations pour le nombre de mots */
      default: character++; /* Par défaut, c'est un caractère qui est comptabilisé */
    }
    n+=1;
    c = sentence[n];
  }
  if (character!=0) {
    word++; // On ajoute le 1er mot si la phrase n'est pas vide
  }
  if (word!=0) {
    line++; // On ajoute la 1ère ligne si elle possède au moins 1 mot
  }
  printf("Nombre de caractères : %d\nNombre de mots : %d\nNombre de lignes : %d\n", character, word, line);
}

int main(int argc, char* argv[]) {
  char sentence[150];

  printf("Ecrivez un texte, nous compterons le nombre de caractères, mots et lignes : ");
  scanf("%[^\n]", sentence);

  wc(sentence);

  return 0;
}
