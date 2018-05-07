
#ifndef NODE_H_
#define NODE_H_

using namespace std;
#include <iostream>

class tnode{
public:
	tnode();
	~tnode();
	void output(ostream& out);
	
	tnode* left;
	tnode* right;
	tnode* parent;
	char character;
	int frequency;

};

class snode {
public:
	snode();
	snode(char input);
	~snode();

	snode* next;
	tnode* root;
	char character;
	int frequency;

};



#endif
