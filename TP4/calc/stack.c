#include "stack.h"
#include <stdio.h>

static Stack stack;

void stack_init(void) {
	stack.size = 0;
	for (int i=0;i<MAX_SIZE;i++) {
		stack.values[i] = -1;
	}
}

int stack_size(void) {
	return stack.size;
}

int stack_is_empty(void) {
	if (stack.size==0) {
		return 1;
	}
	return 0;
}

int stack_top(void) {
	if (!stack_is_empty()) {
		return stack.values[stack.size-1];
	}
	return stack.values[0];
}

int stack_pop(void) {
	if (!stack_is_empty()) {
		stack.size--;
		int top_value = stack.values[stack.size];
		stack.values[stack.size] = -1;
		return top_value;
	}
	return stack.values[0];
}

void stack_push(int n) {
	if (stack.size<MAX_SIZE) {
		stack.values[stack.size] = n;
		stack.size++;
	}
}

void stack_display(void) {
	for (int i=0;i<stack.size;i++) {
		printf("%d ", stack.values[i]);
	}
	printf("\n");
}

int stack_get_element(int index) {
	if (index>=0 && index<MAX_SIZE) {
		return stack.values[index];
	}
	return -1;
}