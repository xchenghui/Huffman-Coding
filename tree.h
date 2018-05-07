#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <fstream>
#include<sstream>
#include"node.h"
#include "stack.h"
#include"list.h"
using namespace std;

class tree {
public:
	//function members
	
    tree();
    ~tree();
	
    void print();
    void set();
    void build(stack *list);
    void printde();
    void visit(tnode *, list123 *);
    void visit1(tnode*);
    tnode* find_char(char alpha);
	
    //data members
    tnode* root;
};

		
	
#endif



