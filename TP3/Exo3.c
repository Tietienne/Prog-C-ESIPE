#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Fonction pour inverser une chaine de caractère */
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
/**************************************************/

int only_letters(char word[]) {
	for(int i = 0; i < strlen(word); i++) {
		if (!(word[i]<='z' && word[i]>='a')) {
			return 0;
		}
	}
	return 1;
}

int only_numbers(char word[]) {
	for(int i = 0; i < strlen(word); i++) {
		if (!(word[i]<='9' && word[i]>='0')) {
			return 0;
		}
	}
	return 1;
}

int convert_base10(char word[]) {
	int result = 0, len = strlen(word), a = 'a'; /* Permet d'avoir des nombres correspondant à une base 26 */
	
	for(int i = 0; i < len; i++) {
		result+=(int) ((word[i]-a+1)*pow(26,(len-i-1)));
	}

	return result;
}

void convert_base26(int word, char *conversion) {
	int quotient = word, remains = 0, a='a'-1, compteur=0;

	while(quotient>26) {
		remains = quotient%26;
		quotient = quotient/26;

		conversion[compteur] = remains+a;
		compteur++;
	}

	conversion[compteur] = quotient+a;
	compteur++;
	conversion[compteur] = '\0';

	strrev(conversion);
}


int main(int argc, char* argv[]) {
	char word[] = "";
	char conversion[] = "";
	printf("Entrez un mot pour la conversion : ");
	scanf("%s", word);

	if (only_letters(word)) {
		printf("Conversion en base 10 : %d\n", convert_base10(word));
	} else if (only_numbers(word)) {
		convert_base26(atoi(word), conversion);
		printf("Conversion en base 26 : %s\n", conversion);
	} else {
		printf("Votre mot n'est pas valide !\n");
	}

	return 0;
}