
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
    void push(char character);
    void push(snode* input);
    void sort();


};
#endif /* STACK_H_ */
