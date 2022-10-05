#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>

#define GROW_VALUE 4

using namespace std;

class Stack {
    public:
        Stack();
        ~Stack();
        void push(int element);
        int pop();
        bool isEmpty();
    private:
        int top;
        int size;
        int* data;
        void error(string error_msg);
};

#endif