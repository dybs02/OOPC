#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;

    for (int i = 1; i < 8; i++) {
        s.push(i);
        printf("Pushed: %d\n", i);
        std::cout << "Is empty: " << s.isEmpty() << std::endl;
        //s.preview();
    }

    for (int i = 0; i < 7; i++) {
        int p = s.pop();
        printf("Popped: %d\n", p);
        std::cout << "Is empty: " << s.isEmpty() << std::endl;
        //s.preview();
    }

//    s.pop();
//    std::cout << "Is empty: " << s.isEmpty() << std::endl;

    return 0;
}
