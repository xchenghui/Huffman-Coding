
#include "tree.h"

using namespace std;

void visit(tnode *node);
tnode* find(tnode *node,char alpha);



tree::tree(){
    root=nullptr;
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
        left->root->parent=input->root;
        right->root->parent=input->root;
        input->frequency=left->frequency+right->frequency;
        input->root->frequency=input->frequency;
        list->push(input);
    }
    root=list->head->root;
}

void visit(tnode *node){
    if(node->left==nullptr&&node->right==nullptr){
        cout<<node->character<<" "<<node->frequency<<" ";
        node->output(cout);
        cout<<endl;
    }
    else{
        visit(node->left);
        visit(node->right);
    }
}



void tree::print(){
    visit(root);
}



tnode* tree::find_char(char alpha){
    return find(root,alpha);
}

tnode* find(tnode *node,char alpha){
    if(!node) return nullptr;
    if(node->character==alpha) return node;
    tnode* Left=find(node->left,alpha);
    if(Left) return Left;
    tnode* Right=find(node->right,alpha);
    if(Right) return Right;
    return nullptr;
}

