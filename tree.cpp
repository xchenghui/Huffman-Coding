
#include "tree.h"

using namespace std;

void visit(tnode *node, list123 w);
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



void tree::printde()
{
	ofstream origin;
	ifstream in3;
	origin.open("decoded.txt");
    in3.open("encoded.txt");
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

void tree::visit(tnode *node, list123 *key){                  // store data to a simple linked list

    if(node->left==NULL&&node->right==NULL){

        key->writeBit('1');                       
        key->writeBit(node->character);

    }
    else{
    	key->writeBit('0');
        visit(node->left, key);
        visit(node->right , key);
    }
}
void tree::visit1(tnode *node)
{
    if(node->left==NULL&&node->right==NULL){
        cout<<node->character<<" "<<node->frequency<<" ";
        node->output(cout);
        cout<<endl;
    }
    else{
        visit1(node->left);
        visit1(node->right);
    }
}


void tree::print(){
	cout<<"Character List:"<<endl;
	visit1(root);
	
}

void tree::set()
{
	list123 w;
	list123 *x = &w;
    visit(root,x);
    w.display();
    

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


