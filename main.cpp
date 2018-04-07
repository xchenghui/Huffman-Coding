
#include <iostream>

using namespace std;
struct Node{
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
void LinkedList:: insert(char alpha){
    if(!head){
        head = new Node();
        head->character = alpha;
        head->frequency = 1;
    }
    
    else if (head->character == alpha) {
        head->frequency=head->frequency+1;
    }
    
    else {
        Node* hold = head;
        while(hold){
            if(hold->character==alpha){
                hold->frequency=head->frequency+1;
                return;
            }
            
            else if(hold->next){
            hold = hold->next;
        }
        
            Node* inserter= new Node();
            hold->next=inserter;
            inserter->character = alpha;
            inserter->frequency = 1;
            }
        }
    }
void LinkedList::printf(){
    Node* printer;
    printer=head;
    while(printer){
        cout<<printer->character<<" "<<printer->frequency<<endl;
        printer=printer->next;
    }
}
