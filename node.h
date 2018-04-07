
#ifndef NODE_H_
#define NODE_H_

using namespace std;

class tnode{
public:
	tnode();
	~tnode();

	tnode *left;
	tnode* right;
	char character;
	int frequency;

};

class snode {
public:
	snode();
	~snode();

	snode* next;
	tnode* root;
	char character;
	int frequency;

};



#endif
