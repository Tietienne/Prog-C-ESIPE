#include <stdio.h>
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

/* Free an integer array */
void free_integer_array(int* tab){
  free(tab);
}

// -----------------  Some functions on arrays

int array_size(int* array) {
  int compteur = 0;
  while (array[compteur]!=-1) {
    compteur++;
  }
  return compteur;
}

void print_array(int* array) {
  int compteur = 0;
  while (array[compteur]!=-1) {
    printf("%d ", array[compteur]);
    compteur++;
  }
  printf("\n");
}

int are_arrays_equal(int* first, int* second) {
  int compteur = 0;
  while (first[compteur]!=-1) {
    if (first[compteur]!=second[compteur]) {
      return 0;
    }
    compteur++;
  }

  // last verification
  if (second[compteur]==-1) {
    return 1;
  }
  return 0;
}

int* copy_array(int* array){
  int* new_array = allocate_integer_array(array_size(array));
  int compteur=0;
  while (array[compteur]!=-1) {
    new_array[compteur] = array[compteur];
    compteur++;
  }

  // copying the end of the array
  new_array[compteur] = -1;
  return new_array;
}

// ----------------- END of some functions



// ----------------- Building arrays

int* fill_array(void) {
  int size=-1, compteur = 0, number = 1;
  while(size<0) {
    printf("Entrez une longueur positive : ");
    scanf("%d", &size);
  }

  int* new_array = allocate_integer_array(size+1);

  while (number!=-1 && compteur<size) {
    printf("Quel nombre voulez-vous ajouter dans la liste (-1 pour arrêter) : ");
    if (scanf("%d", &number)) { // Si pas de problèmes avec scanf --> On ajoute dans la liste.
      new_array[compteur]=number;
      compteur++;
    } else {
      printf("Erreur de saisie !\n");
    }
  }

  if (compteur>=size) {
    printf("Taille maximale de la liste atteinte !\n");
  }

  if (number!=-1) {
    new_array[compteur] = -1;
  }

  return new_array;
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

int* concat_array(int* first, int* second) {
  int size_first = array_size(first);
  int size_second = array_size(second);
  int final_size = size_first + size_second;

  int* new_array = allocate_integer_array(final_size);

  for (int i=0; i<size_first; i++) {
    new_array[i] = first[i];
  }
  for (int j=0; j<size_second; j++) {
    new_array[size_first+j] = second[j];
  }

  new_array[size_first+size_second] = -1;

  return new_array;
}

// ----------------- END of building arrays


// ----------------- Merge Sort

int* merge_sorted_arrays(int* first, int* second) {
  int size_first = array_size(first);
  int size_second = array_size(second);
  int final_size = size_first + size_second;

  int* new_array = allocate_integer_array(final_size+1);

  int i=0, j=0;

  while(i<size_first && j<size_second) {
    if (first[i]<=second[j]) {
      new_array[i+j]=first[i];
      i++;
    } else {
      new_array[i+j]=second[j];
      j++;
    }
  }

  while(i<size_first) {
    new_array[i+j]=first[i];
    i++;    
  }

  while(j<size_second) {
    new_array[i+j]=second[j];
    j++;    
  }

  new_array[i+j] = -1;
  return new_array;
}

void split_arrays(int* array, int** first, int** second) {
  int size = array_size(array);
  int* first_array = allocate_integer_array(size/2);
  int* second_array = allocate_integer_array((size/2)+1);

  int i;
  for (i=0;i<size/2;i++) {
    first_array[i]=array[i];
  }
  first_array[i]=-1;

  for (i=size/2;i<size;i++) {
    second_array[i-(size/2)]=array[i];
  }
  second_array[i-(size/2)]=-1;

  *first = first_array;
  *second = second_array;
}

void print_mergeArrays(int* returning_array, int* array1, int* array2) {
  print_array(array1);
  print_array(array2);
  print_array(returning_array);
}

int* merge_sort(int* array) {
  int* array_part1;
  int* array_part2;
  split_arrays(array, &array_part1, &array_part2);
  if (array_size(array_part1)==0) {
    return array_part2;
  }
  printf("Split array in two part :\n");
  print_array(array);
  print_array(array_part1);
  print_array(array_part2);
  int* returning_array = merge_sorted_arrays(merge_sort(array_part1), merge_sort(array_part2));
  printf("Merge the following ones : \n");
  print_mergeArrays(returning_array, array_part1, array_part2);
  return returning_array;
}

// ----------------- END of Merge Sort

/* An empty main to test the compilation of the allocation and free
   functions. */
int main(int argc, char* argv[]){

  // Exercice 1 tests

  int* array = allocate_integer_array(5);
  array[0]=5;
  array[1]=-6;
  array[2]=10;
  array[3]=1;
  array[4]=0;
  array[5]=-1;

  if (array_size(array)==5) {
    printf("Taille OK de la 1ère liste : %d\n", array_size(array));
  } else {
    printf("ERREUR : Taille de la 1ère liste | 5 != %d\n", array_size(array));
  }
  

  printf("Array 1 : ");
  print_array(array);

  int* array2 = copy_array(array);

  printf("Array 2 (Copie de la 1ère) : ");
  print_array(array2);

  printf("Array 1 = Array 2 ? %d\n\n", are_arrays_equal(array, array2));

  free_integer_array(array);
  free_integer_array(array2);

  // END of Exercice 1 tests


  // Exercice 2 tests

  int* array3 = fill_array();

  print_array(array3);

  int* array4 = random_array(10, 100);

  printf("Tableau aléatoire de taille 10 (0-100): ");
  print_array(array4);

  int* array5 = concat_array(array3, array4);
  printf("Concaténation des 2 tableaux précédents : ");
  print_array(array5);

  free_integer_array(array3);
  free_integer_array(array4);
  free_integer_array(array5);

  // END of Exercice 2 tests


  // Exercice 3 tests

  int* array6 = allocate_integer_array(4);
  array6[0]=1;
  array6[1]=3;
  array6[2]=4;
  array6[3]=7;
  array6[4]=8;
  array6[5]=-1;

  int* array7 = allocate_integer_array(4);
  array7[0]=1;
  array7[1]=2;
  array7[2]=6;
  array7[3]=-1;

  printf("\nArray 6 : ");
  print_array(array6);

  printf("Array 7 : ");
  print_array(array7);

  printf("Tri des 2 tableaux précédents : ");
  print_array(merge_sorted_arrays(array6, array7));

  int* array6_1 = allocate_integer_array(10);
  int* array6_2 = allocate_integer_array(10);

  printf("Split du tableau 6 : \n");
  split_arrays(array6, &array6_1, &array6_2);
  print_array(array6_1);
  print_array(array6_2);

  printf("\nNow a random array of length 20 whose entries are lower than 100 : \n");
  int* array8 = random_array(20, 100);
  print_array(array8);
  array8 = merge_sort(array8);
  printf("Here is the sorted array : \n");
  print_array(array8);

  free_integer_array(array6);
  free_integer_array(array6_1);
  free_integer_array(array6_2);
  free_integer_array(array7);
  free_integer_array(array8);

  // END of Exercice 3 tests

  return 0;
}
