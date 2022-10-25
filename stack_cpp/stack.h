#ifndef _STACK_H_
#define _STACK_H_

#include <string>
#include <iostream>

#define GROW_VALUE 4

using namespace std;

class Stack {
  public:
	Stack();
	~Stack();
	void push(int element);
	int pop();
	bool isEmpty();
	void preview();

  private:
	int top;
	int size;
	int* data;
	void resize(int value);
	void error(string error_msg);
};

#endif
