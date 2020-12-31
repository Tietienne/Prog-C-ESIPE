#include <stdio.h>
#include <stdlib.h>

void print_array(int* array, int size) {
  for (int i=0;i<size;i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int placeAvailable(int buffer[], int index, int max) {
	for(int i=index;i<max;i++) {
		if (buffer[i]==0) {
			return i;
		}
	}
	return -1;
}

void permutations(int buffer[], int current, int max) {
	if (current>max) {
		print_array(buffer, max);
		return;
	}

	int place = placeAvailable(buffer, 1, max);
	buffer[place]=current;
	permutations(buffer, current+1, max);
	buffer[place]=0;

/*	for (int i=0;i<max;i++) {
		int place = placeAvailable(buffer, i, max);
		buffer[place]=current;
		permutations(buffer, current+1, max);
		buffer[place]=0;
	}*/
}

int main(int argc, char* argv[]){
	int buffer[] = {0, 0, 0};
	permutations(buffer, 1, 3);
	return 0;
}