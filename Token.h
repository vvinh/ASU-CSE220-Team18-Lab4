//
//  Token.h
//  Lab4
//
//  Created by Bryce Holton.
//

#ifndef __Lab4__Token__
#define __Lab4__Token__

#include <iostream>
#include "common.h"

using namespace std;

/**************
 this is a valid Pascal token.  A token must have a literal type,
 a literal value, and a token code.
 ***************/
class Token {
private:
	TokenCode code;
	LiteralType type;
	union {
		int integer;
		float real;
		char *stringLiteral;
	} literal;
	string tokenString;
	string lineNumber;
	//`What variables and methods am I missing to implement a binary tree.
	Token* leftChild = NULL; //pointer to left node
	Token* rightChild = NULL; // pointer to right node

public:
	Token();
	~Token();

	void setCode(TokenCode newCode);
	TokenCode getCode();

	void setType(LiteralType newType);
	LiteralType getType();

	void setLiteral(int newInteger);
	int getIntLiteral();
	void setLiteral(float newReal);
	float getRealLiteral();
	void setLiteral(string newString);
	string getStringLiteral();

	void setTokenString(string s);
	string getTokenString();

	//void setNextToken(Token *newToken); // don't know what this is for?
	//Token* getNextToken();

	void setLeftChild(Token *childToken); //set current node left child
	Token* getLeftChild();
	Token** getLeftChildAddr();

	void setRightChild(Token *childToken); // set current node right child
	Token* getRightChild();
	Token** getRightChildAddr();

	void setLineNumber(string s);
	string getLineNumber();

};

#endif /* defined(__Lab4__Token__) */
