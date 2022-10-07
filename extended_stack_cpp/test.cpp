#include <stdio.h>
#include "stack.h"

//int main() {
//    Stack s = Stack();
//
//    for (int i = 1; i < 8; i++) {
//        s.push(i);
//        printf("Pushed: %d\n", i);
//        std::cout << "Is empty: " << s.isEmpty() << std::endl;
//        s.preview();
//    }
//
//    for (int i = 0; i < 7; i++) {
//        int p = s.pop();
//        printf("Popped: %d\n", p);
//        std::cout << "Is empty: " << s.isEmpty() << std::endl;
//        s.preview();
//    }
//
////    s.pop();
////    std::cout << "Is empty: " << s.isEmpty() << std::endl;
//
//    return 0;
//}

//int main() {
//    Stack s1 = Stack();
//    s1.push(12);
//    s1.push(33);
//    s1.push(33);
//    s1.push(33);
//    s1.push(33);
//    s1.push(33);
//    s1.preview();
//
//    Stack s2 = Stack(s1);
//    s2.preview();
//
//    s1.pop();
//    s1.pop();
//    s1.push(55);
//
//    s1.preview();
//    s2.preview();
//
//    return 0;
//}

int main() {

    Stack s1 = Stack();
    Stack s2 = Stack();
    s1.push(12);
    s1.push(13);
    s1.push(14);
    s1.push(15);
    s1.push(16);

    s1.preview();
    s2.preview();

    s2 = s1;

    s1.preview();
    s2.preview();

    s1.pop();
    s1.pop();
    s2.push(99);

    s1.preview();
    s2.preview();

    return 0;
}