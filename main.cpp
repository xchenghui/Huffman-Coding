#include <iostream>



using namespace std;



class tnode{

public:

	tnode();

	~tnode();



	tnode* left;

	tnode* right;

	char character;

	int frequency;



};



class snode {

public:

	snode();
	snode(char input);
	~snode();



	snode* next;

	tnode* root=new tnode();

	char character;

	int frequency;



};

class stack {
public:
    snode* head=NULL;
    int size=0;

    stack();
    stack(string str);
    //~stack();
    snode* pop();               //Pop the top of stack.
    void push(char alpha);      //Read from character, pushed onto the stack.
    //void push(snode* input);    //Pushing the node into the stack. This is broken please change the variable.
    void duplicate();
    void sort();                //Quick Sort
    void remove();
    void printf();              //Test case.

};

class tree {

public:

    tree();

   // ~tree();

    //void build(stack *list);



    tnode* root=NULL;

};

int main()

{   string in;

    cin >> in;

    stack newlist(in);

    newlist.duplicate();
    newlist.printf();
    
    return 0;

}



stack::stack(){

    head->character=NULL;

    head->frequency=0;

}



stack::stack(string str){

    char store;

    for(int i=0; i<str.length(); i++){

        store=str[i];

        push(store);

    }

}



void stack::push(char alpha){

    if(!head){

        head = new snode(alpha);
        size=1;
    }

    else {

        snode* hold = head;

        while(hold){

            if(hold->character==alpha){

                hold->frequency=hold->frequency+1;

                return;

            }

            

            else if(hold->next){

            hold = hold->next;

            }

            else{

                break;

            }

        }

            snode* inserter = new snode(alpha);

            hold->next=inserter;
            size++;

    }

}

    

void stack::printf(){

    snode* printer;

    printer=head;

    while(printer){

        cout<<printer->character<<" "<<printer->frequency<<endl;
        cout<<printer->root->character<<" "<<printer->root->frequency<<endl;
        printer=printer->next;

    }

}

void stack::duplicate(){

    snode* printer;
    printer=head;

    while(printer){
    //Duplicate all stack nodes to tree nodes;
        printer->root->character = printer->character;
        printer->root->frequency = printer->frequency;
        printer=printer->next;
    }

}

tree::tree(){

	root=NULL;

}



/*tree::~tree() {

	delete root;

}*/



/*void tree::build(stack *list){

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

}*/

snode::snode(char input) {
    character = input;
    frequency=1;
    next=NULL;
}

tnode::tnode() {
    character = NULL;
    frequency = 0;
}
