 
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "node.h"

using namespace std;


class stack {
public:
    snode* head;
    int size;

    stack();
    ~stack();
    snode* pop();
    void duplicate();
    void push(char character);  //read from character, puched onto the stack.
    void push(snode* input);    //pushing the node into the stack.
    void sort();
    void remove();

};
#endif /* STACK_H_ */
