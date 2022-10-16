#include "stack.h"

using namespace std;
std::vector<Stack*> all_stacks;

Stack::Stack() {
    this->top = 0;
    this->size = GROW_VALUE;
    all_stacks.push_back(this);

    this->data = (int*) malloc(this->size*sizeof(int));
    if (!this->data) this->error("Error while allocating memory");
}

Stack::~Stack() {
    free(this->data);
}

void Stack::push(int element){
    if (this->top >= this->size)
        this->resize(GROW_VALUE);

    this->data[this->top++] = element;
}

int Stack::pop(){
    if (this->top <= 0) error("Error: calling pop on empty stack");

    if (this->size - this->top > GROW_VALUE)
        this->resize(-GROW_VALUE);

    return this->data[--this->top];
}

bool Stack::isEmpty(){
    return this->top == 0;
}

void Stack::resize(int value) {
    this->size += value;
    int *temp = (int*) realloc(this->data, this->size * sizeof(int));
    if (temp) {
        this->data = temp;
    } else {
        free(temp);
        this->error("Error while allocating memory");
    }
}

void Stack::error(string error_msg) {
    for (Stack* s : all_stacks) {
        free(s->data);
    }
    cout << error_msg << endl;
    abort();
}

void Stack::preview() {
    printf("Size=%d\tTop=%d\n", this->size, this->top);

    for (int i = 0; i < this->size; i++) {
        printf("stack[%d] = %d\n", i, this->data[i]);
    }

    printf("\n");
}
















