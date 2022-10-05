#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"


void error(Stack* s, char* error_msg) {
    free(s->data);
    printf("%s\n", error_msg);
    abort();
}

void resize(Stack* s, int value) {
    s->size += value;
    int *temp = realloc(s->data, s->size * sizeof(int));
    if (temp) {
        s->data = temp;
    } else {
        free(temp);
        error(s, "Error while allocating memory");
    }
}

void init(Stack* s) {
    s->top = 0;
    s->size = GROW_VALUE;

    s->data = malloc(s->size*sizeof(int));
    if (!s->data) {
        error(s, "Error while allocating memory");
    }
}

void destroy(Stack* s) {
    s->top = 0;
    s->size = GROW_VALUE;
    free(s->data);
}

void push(Stack* s, int element) {
    if (s->top >= s->size) {
        resize(s, GROW_VALUE);
    }
    s->data[s->top++] = element;
}

int pop(Stack* s) {
    if (s->top <= 0) error(s, "Error: calling pop on empty stack");

    if (s->size - s->top > GROW_VALUE) {
        resize(s, -GROW_VALUE);
    }

    return s->data[--s->top];
}
bool isEmpty(Stack* s) {
    return s->top == 0;
}

void preview(Stack* s) {
    printf("Size=%d\tTop=%d\n", s->size, s->top);

    for (int i = 0; i < s->size; i++) {
        printf("stack[%d] = %d\n", i, s->data[i]);
    }
    printf("\n");
}