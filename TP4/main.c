#include "stack.c"

int main(int argc, char* argv[]) {
	stack_init();
	printf("Taille : %d\nVide ? %d\n", stack_size(), stack_is_empty()); // Affiche 0, 1
	stack_push(26);
	stack_push(2);
	stack_push(-20);
	stack_push(0);
	printf("Pile : ");
	stack_display(); // Affiche 26 2 -20 0
	printf("Taille : %d\nVide ? %d\nTop : %d\n", stack_size(), stack_is_empty(), stack_top()); // Affiche 4, 0, 0
	stack_pop();
	printf("Pop : %d\n", stack_pop()); // Affiche -20
	printf("Pile : ");
	stack_display(); // Affiche 26 2
	printf("Index 10 : %d\n", stack_get_element(10)); // Affiche -1
	printf("Index 1 : %d\n", stack_get_element(1)); // Affiche 2

	for (int i=0;i<20;i++) {
		stack_push(5);
	}

	printf("Taille : %d\n", stack_size()); // Affiche 15
	stack_display(); // Affiche 26 2 5 5 5 5 5 5 5 5 5 5 5 5 5

	return 0;
}