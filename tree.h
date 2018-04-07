
#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include"node.h"
#include "stack.h"

using namespace std;


class tree {
public:
    tree();
    ~tree();
    void build(stack *list);

    tnode* root;
};

#endif
