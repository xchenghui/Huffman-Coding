#include <iostream>
#include "stack.h"
#include "tree.h"
#include <fstream>

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
}


int main(){

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
    return 1;
}

