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
    //data.printde();
    data.print();
    
    //ofstream 
    char alpha;
    tnode* temp;
    while(in2.get(alpha)){
        temp=data.find_char(alpha);
        if(temp) temp->output(out);
        else cout<<"error"<<endl;
    }
    
    
}
void decode(istream &in, istream &in2)          // have to build tree to get root.
{
    stack *list=read(in);
    list->sort();
    list->duplicate();
    tree data;
    data.build(list);
    data.printde();
}

int main(){
    
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
    //decode(in,in2,out);
    //test1.printde();
    //ifstream in;
    in.open("test.txt");
    //ifstream in2;
    in2.open("test.txt");
    decode(in,in2);
    in.close();
    in2.close();
    
    return 0;
}
