#include "stack.h"

using namespace std;

stack::stack() {
    head=NULL;
    size=0;

}

stack::~stack() {

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

            else break;
        }
        snode* inserter = new snode(alpha);

        hold->next=inserter;
        size++;
    }
}

void stack::duplicate(){
    snode* printer=head;
    while(printer){
        //Duplicate all stack nodes to tree nodes;
        printer->root=new tnode;
        printer->root->character = printer->character;
        printer->root->frequency = printer->frequency;
        printer=printer->next;
    }
}

void stack::push(snode *input){
    if(head==NULL) head=input;
    else{
        snode *go=head;
        snode *old=NULL;
        while(go){
            if(go->frequency>=input->frequency){
                break;
            }
            old=go;
            go=go->next;

        }
        input->next=go;
        if(old==NULL) head=input;
        else old->next=input;
    }
    size++;
}

snode* stack::pop(){
    snode* temp=head;
    if(head){
        head=head->next;
        size--;
    }
    return temp;
}

void stack::sort(){
    snode* go=head;
    snode* min=head;
    snode* current=head;
    while(current->next){
        go=current;
        while(go->next){
            if(go->frequency>go->next->frequency) min=go->next;
            go=go->next;
        }
       if(current!=min){
           char temp_char=min->character;
           int temp_freq=min->frequency;
           min->frequency=current->frequency;
           min->character=current->character;
           current->character=temp_char;
           current->frequency=temp_freq;
       }
        current=current->next;
    }
}
