#include "list.h"


void list123::writeBit(char nu)
{
	node1 *newNode;
	node1 *nodePtr;
	newNode = new node1;
	newNode->data = nu;
	newNode->next = NULL;
	if(!head)
	{
		head = newNode;
	 } 
	 else
	 {
	 	nodePtr = head;
	 	while(nodePtr->next)
	 	{
	 		nodePtr = nodePtr->next;
		 }
		 nodePtr->next = newNode;
	 }
}
void list123::display()              // store data to key.txt;
{
	ofstream key;
	key.open("key.txt");
	node1 *nodePtr;
	nodePtr = head;
	while(nodePtr)
	{
		key<<nodePtr->data;
		cout<<nodePtr->data;
		nodePtr = nodePtr->next;
	}
	key.close();
}

