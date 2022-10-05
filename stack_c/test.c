#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;

    init(&s);

    for (int i = 1; i < 8; i++) {
        push(&s, i);
        printf("Pushed: %d\n", i);
//        preview(&s);
    }

    for (int i = 0; i < 7; i++) {
        int p = pop(&s);
        printf("Popped: %d\n", p);
//        preview(&s);
    }

    destroy(&s);
    return 0;
}