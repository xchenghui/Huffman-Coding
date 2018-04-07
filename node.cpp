

#include "node.h"

snode::snode() {
	next=NULL;
	root=NULL;
	character=NULL;
	frequency=0;
}

snode::~snode() {

}

tnode::tnode(){
	character=NULL;
	frequency=0;
	right=NULL;
	left=NULL;
}

tnode::~tnode(){

}
