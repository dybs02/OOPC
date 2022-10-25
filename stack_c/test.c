#include "stack.h"
#include <stdio.h>

int main()
{
	Stack s1, s2;

	init(&s1);
	init(&s2);

	for (int i = 1; i < 8; i++) {
		push(&s1, i);
		printf("Pushed to s1: %d\n", i);
		// preview(&s1);
	}
	for (int i = 1; i < 8; i++) {
		push(&s2, i);
		printf("Pushed to s2: %d\n", i);
		// preview(&s2);
	}

	for (int i = 0; i < 7; i++) {
		int p = pop(&s1);
		printf("Popped from s1: %d\n", p);
		// preview(&s1);
	}
	for (int i = 0; i < 7; i++) {
		int p = pop(&s2);
		printf("Popped from s2: %d\n", p);
		// preview(&s2);
	}

	destroy(&s1);
	destroy(&s2);

	return 0;
}
