#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define GROW_VALUE 4

typedef struct {
	int top;
	int size;
	int* data;
} Stack;

void error(Stack* s, char* error_msg);
void resize(Stack* s, int value);
void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool isEmpty(Stack* s);
void preview(Stack* s);

#endif
