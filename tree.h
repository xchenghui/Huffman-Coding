#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <fstream>
#include"node.h"
#include "stack.h"

using namespace std;


class tree {
public:
	//function members
    tree();
    ~tree();

    void print();
    void build(stack *list);

    void printde();
    tnode* find_char(char alpha);

    //data members
    tnode* root;
};

#endif



