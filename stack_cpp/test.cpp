#include <stdio.h>
#include "stack.h"

int main() {
    Stack s1 = Stack();
    Stack s2 = Stack();

    for (int i = 1; i < 8; i++) {
        s1.push(i);
        printf("Pushed: %d\n", i);
        std::cout << "Is empty: " << s1.isEmpty() << std::endl;
        s1.preview();
    }
    for (int i = 41; i < 48; i++) {
        s2.push(i);
        printf("Pushed: %d\n", i);
        std::cout << "Is empty: " << s2.isEmpty() << std::endl;
        s2.preview();
    }

    for (int i = 0; i < 7; i++) {
        int p = s1.pop();
        printf("Popped: %d\n", p);
        std::cout << "Is empty: " << s1.isEmpty() << std::endl;
        s1.preview();
    }
    for (int i = 0; i < 7; i++) {
        int p = s2.pop();
        printf("Popped: %d\n", p);
        std::cout << "Is empty: " << s2.isEmpty() << std::endl;
        s2.preview();
    }

    s1.pop();

    return 0;
}