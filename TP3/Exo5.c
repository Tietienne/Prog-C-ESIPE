#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int* allocate_integer_array(int size){
  int* new_tab;

  new_tab = (int*)malloc((size+1)*sizeof(int));
  if (new_tab == NULL){
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  new_tab[0]=-1;
  return new_tab;
}

int* random_array(int size, int max_entry) {
  int * new_array = allocate_integer_array(size);
  int i;

  srand(time(NULL));

  for (i=0;i<size;i++) {
    new_array[i] = rand() % max_entry+1;
  }

  new_array[i] = -1;

  return new_array;
}

void print_array(int* array) {
  int compteur = 0;
  while (array[compteur]!=-1) {
    printf("%d ", array[compteur]);
    compteur++;
  }
  printf("\n");
}

void tri_bulle(int* tab, int size) {
	int tmp;
	for (int i=0 ; i < size-1; i++){
	    for (int j=0 ; j < size-i-1; j++){
	    	if (tab[j] > tab[j+1]){
	    		tmp = tab[j];
	    		tab[j] = tab[j+1];
	    		tab[j+1] = tmp;
	    	}
	    }
	}
}

int main(int argc, char* argv[]) {
	int* tab1 = random_array(20, 10);
	int* tab2 = random_array(20, 100);
	int* tab3 = random_array(20, 1000);

	print_array(tab1);
	printf("--- Après tri ---\n");
	tri_bulle(tab1, 20);
	print_array(tab1);
	printf("\n");

	print_array(tab2);
	printf("--- Après tri ---\n");
	tri_bulle(tab2, 20);
	print_array(tab2);
	printf("\n");

	print_array(tab3);
	printf("--- Après tri ---\n");
	tri_bulle(tab3, 20);
	print_array(tab3);

	return 0;
}