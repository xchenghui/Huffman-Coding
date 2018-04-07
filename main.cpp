/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
    Node();
    Node(char input);
  int frequency;
  char character;
  Node* next;
};

struct LinkedList{
    LinkedList();
    LinkedList(string str);
    //~LinkedList;
  Node* head = NULL;
  void insert(char alpha);
  void printf();
  //void delete;
};

int main()
{   string in;
    cin >> in;
    LinkedList newlist(in);
    newlist.printf();
    return 0;
}

LinkedList::LinkedList(){
    head->character=NULL;
    head->frequency=0;
}

LinkedList::LinkedList(string str){
    char store;
    for(int i=0; i<str.length(); i++){
        store=str[i];
        insert(store);
    }
}

void LinkedList::insert(char alpha){
    if(!head){
        head = new Node(alpha);
    }
    
    else if (head->character == alpha) {
        head->frequency=head->frequency+1;
    }
    
    else {
        Node* hold = head;
        while(hold){
            if(hold->character==alpha){
                hold->frequency=hold->frequency+1;
                return;
            }
            
            else if(hold->next){
            hold = hold->next;
            }
        
            Node* inserter = new Node(alpha);
            hold->next=inserter;
        }
    }
}
    
void LinkedList::printf(){
    Node* printer;
    printer=head;
    while(printer->next){
        cout<<printer->character<<" "<<printer->frequency<<endl;
        printer=printer->next;
    }
}

Node::Node(){
    character=NULL;
    frequency=0;
    next=NULL;
}
Node::Node(char input){
    character=input;
    frequency=1;
}
