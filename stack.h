#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

typedef struct {
    int top;
    size_t size;
    int* data;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
//bool isEmpty(Stack* s);

#endif