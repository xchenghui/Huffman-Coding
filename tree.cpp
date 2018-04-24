
#include "tree.h"

using namespace std;

void visit(tnode *node);
tnode* find(tnode *node,char alpha);



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
        left->root->parent=input->root;
        right->root->parent=input->root;
        input->frequency=left->frequency+right->frequency;
        input->root->frequency=input->frequency;
        list->push(input);
    }
    root=list->head->root;
}

void visit(tnode *node){
   //cout<<node->character<<endl;
    if(node->left==NULL&&node->right==NULL){
        cout<<node->character<<" "<<node->frequency<<" ";
        node->output(cout);
        cout<<endl;
    }
    else{
        visit(node->left);
        visit(node->right);
    }
}


void tree::printde()
{
    ofstream origin;
    ifstream in3;
    origin.open("orginal_file.txt");
    in3.open("output.txt");
    if(in3.is_open()&&origin.is_open())
    {
        string line;
        string bin;
        string temp= "";
    while(getline(in3,line))
    {
    istringstream s(line);
    s>>bin; 
    }
    //cout<<bin;
    tnode *node = root;             // set initial travel node pointer is root.
    
    for(int i =0; i<= bin.size();i++)
    {
    if(bin[i]== '0')            // when string is 0, go left.
    {  
        node = node->left;
     }
     else
     {
        node = node->right;        // else, go right.
     }
     if(node->left == NULL && node->right== NULL)
     {
        temp = temp + node->character;
        cout<<node->character;         // print orginal file.
        origin << node->character;
        node = root;
     
    }
    in3.close();
    
 }
 origin.close();
}
}
 //cout<<node1->character<<" "<<node1->character<<endl;
 
    //cout<<temp;
 
 
    //cout<<bin<<endl;
    //cout<<bin.size();     
    
    //return temp;
    
    



void tree::print(){

    //cout<<root->character<<" "<<root->frequency<<" ";
    //root->output(cout);
    visit(root);
}



tnode* tree::find_char(char alpha){
    return find(root,alpha);
}

tnode* find(tnode *node,char alpha){
    if(!node) return NULL;
    if(node->character==alpha) return node;
    tnode* Left=find(node->left,alpha);
    if(Left) return Left;
    tnode* Right=find(node->right,alpha);
    if(Right) return Right;
    return NULL;
}
