#include <stdio.h>

int main(int argc, char* argv[]) {
  FILE* f = NULL;
  f = fopen("Exo5.c", "r"); /* On ouvre le fichier source du code */
  int c = 0;

  if (f!=NULL) { /* Si le fichier est trouvé */
    c = fgetc(f); /* On récupère les caractères un par un */
    while (c!=EOF) { /* Tant qu'on ne tombe pas sur la fin du fichier, on continue de le lire */
      printf("%c", c); /* On affiche caractère par caractère */
      c = fgetc(f);
    }
  } else {
    printf("Erreur : Impossible de trouver le code source !\n");
  }

  fclose(f);

  return 0;
}
