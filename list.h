#ifndef LIST123_H
#define LIST123_H
#include <iostream>
#include <fstream>
#include<sstream>
#include<stdlib.h>
#include<string>
using namespace std;
class list123{
	public:
	struct node1
	{
		char data;
		node1 *next;
		};
	node1 *head;
	
	
	
	void writeBit(char);
	void display();
	
	list123()
	{
		head = NULL;
	}

		
	};
	

#endif
