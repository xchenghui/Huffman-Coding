
#include <iostream>

using namespace std;

struct Node{
    Node();
    Node(char input);
  int frequency;
  char character;
  Node* right;
  Node* left;
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

struct tree{
    tree();
    //void insert(char alpha and maybe int frequency);
    //~tree();
    Node* root = NULL;
};

struct stack{
    //stack();
    //void getTop();
    //Node* top = Null;
    //Node* end = Null;
    //void pop();
    //void push();
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
            if(alpha==hold->character){
                hold->frequency=hold->frequency+1;
                return;
            }
            
            else if(hold->right){
            hold = hold->right;
            }
            else{
                break;
            }
        }
            Node* inserter = new Node(alpha);
            hold->right=inserter;
    }
}
    
void LinkedList::printf(){
    Node* printer;
    printer=head;
    while(printer){
        cout<<printer->character<<" "<<printer->frequency<<endl;
        printer=printer->right;
    }
}

Node::Node(){
    character=NULL;
    frequency=0;
    right=NULL;
    left=NULL;
}
Node::Node(char input){
    character=input;
    frequency=1;
}

tree::tree(){
    root->character=NULL;
    root->frequency=0;
}
