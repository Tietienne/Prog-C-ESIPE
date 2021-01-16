#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int size) {
  for (int i=0;i<size;i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void permutations(int buffer[], int current, int max) {
	if (current>max) {
		print_array(buffer, max);
		return;
	}

	for (int i=0;i<max;i++) {
		if (buffer[i]==0) {
			buffer[i]=current;
			permutations(buffer, current+1, max);
			buffer[i]=0;
		}
	}
}

int main(int argc, char* argv[]){
	int buffer[] = {0, 0, 0};
	printf("Permutations de taille 3 :\n");
	permutations(buffer, 1, 3);
	return 0;
}