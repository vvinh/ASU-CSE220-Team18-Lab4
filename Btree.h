#ifndef __Lab4__Btree__
#define __Lab4__Btree__

#include "common.h"
#include "Token.h"

class Btree {

private:
	Token* rootPtr = NULL; //pointer to root node

public:
	Btree(Token* rootPointer);
	~Btree();
	void setRootNode(Token* rootNodePtr);
	Token* getRootNode();
	void insertNode(Token* rootPointer, string tokenString, Token* node);
	void inOrder(Token* ptr) ;

};

#endif

