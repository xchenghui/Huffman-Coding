

#include "node.h"


snode::snode() {
    next= NULL;
    root=NULL;
    character='\0';
    frequency=0;
}

snode::snode(char input) {
    root=NULL;
    character = input;
    frequency=1;
    next=NULL;
}

snode::~snode() {
    delete this;
}

tnode::tnode(){
    character='\0';
    parent=NULL;
    frequency=0;
    right=NULL;
    left=NULL;
}

tnode::~tnode(){

}

struct node{
    node(int x){
        data=x;
        next=NULL;
    }
    int data;
    node* next;
};

struct out_storage{
    node* head;
    out_storage(){
        head= NULL;
    }
    void push(int x){
        if(!head)head=new node(x);
        else{
            node* temp=head;
            head=new node(x);
            head->next=temp;
        }
    }
    int pop(){
        if(head){
            node* temp=head;
            head=head->next;
            return temp->data;
        }
        return -1;
    }
};

void tnode::output(ostream& out){
    out_storage output;
    tnode *go=this;
    while(go->parent){
        if(go->parent->left==go) output.push(0);
        else output.push(1);
        go=go->parent;
    }

    while(output.head){
        int data=output.pop();
        out<<data;
    }
}

