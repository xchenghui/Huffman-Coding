

#include "tree.h"

using namespace std;

tree::tree(){
	root=NULL;
}

tree::~tree() {
	delete root;
}

void tree::build(stack *list){
	snode *left,*right,*input;
	    while(list->size>1){
	        left=list->pop();
	        right=list->pop();
	        input=new snode;
	        input->root=new tnode;
	        input->root->left=left->root;
	        input->root->right=right->root;
	        input->frequency=left->frequency+right->frequency;
	        input->root->frequency=input->frequency;
	        list->push(input);
	    }
	    root=list->head->root;
}

