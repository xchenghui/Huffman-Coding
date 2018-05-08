#include <iostream>
#include "stack.h"
#include "tree.h"
#include <fstream>
#include<sstream>

stack* read(istream &in){
    stack *list=new stack;
    char alpha;
    while(in.get(alpha)){
        list->push(alpha);
    }
    return list;
}

void compress(istream &in,istream &in2,ostream &out){
    stack *list=read(in);
    list->sort();
    list->duplicate();
    tree data;
    data.build(list);
    data.print();
    
    char alpha;
    tnode* temp;
    while(in2.get(alpha)){
        temp=data.find_char(alpha);
        if(temp) temp->output(out);
        else cout<<"error"<<endl;
    }
    data.set();
}

void recur(ifstream &key, tnode *node1)
{
	char x;
	if(!key.get(x))
	{
		
	}
	else if(x == '1')
	{
		key.get(x);
		if(node1->left == NULL){
		
		node1->left = new tnode;
		node1->left->parent = node1;
		node1->left->character = x;
		}
		else
		{
			node1->right = new tnode;
			node1->right->parent = node1;
			node1->right->character = x;
		}
		if(node1->right == NULL )
		{
			recur(key, node1);
			}
	}
	else if(x == '0')
	{
		if(node1->left == NULL)
		{
			node1->left = new tnode;
			node1->left->parent = node1;
			recur(key,node1->left);
			recur(key,node1);
		}
		if(node1->right==NULL)
		{
			node1->right = new tnode;
			node1->right->parent = node1;
			recur(key, node1->right);	
		}
	}
}

void decode(ifstream &key)
{
	char x;
	tree deco;
	deco.root = new tnode;
	key.get(x);
	recur(key, deco.root);
	deco.print();
	cout<<endl<<"Text result:"<<endl;
	deco.printde();
	cout<<endl;
}


int main(){
	
	int state=0;
	while(state!=3){
		cout<<endl<<"1. Encode"<<endl<<"2. Decode"<<endl<<"3. Exit"<<endl;
		cin>>state;
		if(state==1){
			//tree test1;
		    ifstream in;
		    in.open("test.txt");
		    ifstream in2;
		    in2.open("test.txt");
		    ofstream out;
		    out.open("output.txt");
		    compress(in,in2,out);
		    in.close();
		    in2.close();
		    out.close();
		}
		else if(state==2){
			ifstream in;
		    in.open("key.txt");
		    decode(in);
		    in.close();
		}
	}

    return 0;
}

