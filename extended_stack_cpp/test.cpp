#include <stdio.h>
#include "stack.h"

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
    s2.push(555);
    s2.push(999);

//    s1.preview();
//    s2.preview();

//    s2 = s1;
    s1 = s2;

//    s1.preview();
//    s2.preview();

    s1.pop();
    s1.pop();
    s2.push(99);

//    s1.preview();
//    s2.preview();

    return 0;
}