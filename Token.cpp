//
//  Token.cpp
//  Lab4
//
//  Created by Bryce Holton.
//

#include "Token.h"
#include <stdlib.h>

Token::Token()
{
    //`What code do I need here to initialize everything.
}
Token::~Token()
{
    //`What code do I need here to free memory
}
void Token::setCode(TokenCode newCode)
{
    this->code = newCode;
}
TokenCode Token::getCode()
{
    return this->code;
}
void Token::setType(LiteralType newType)
{
    this->type = newType;
}
LiteralType Token::getType()
{
    return this->type;
}
void Token::setLiteral(int newInteger)
{
    this->literal.integer = newInteger;
}
int Token::getIntLiteral()
{
    return this->literal.integer;
}
void Token::setLiteral(float newReal)
{
    this->literal.real = newReal;
}
float Token::getRealLiteral()
{
    return this->literal.real;
}
void Token::setLiteral(string newString)
{
    this->literal.stringLiteral = (char*)malloc(sizeof(char) * newString.length() + 1);
    strcpy(this->literal.stringLiteral, newString.c_str());
}
string Token::getStringLiteral()
{
    return string(this->literal.stringLiteral);
}
void Token::setTokenString(string s)
{
    this->tokenString = s;
}
string Token::getTokenString()
{
    return this->tokenString;
}




void Token::setLeftChild(Token *childToken)
{
    this->leftChild = childToken;
}
Token* Token::getLeftChild()
{
    return this->leftChild;

}


Token** Token::getLeftChildAddr() {
	return &(this->leftChild);
}

void Token::setRightChild(Token *childToken)
{
    this->rightChild = childToken;
}
Token* Token::getRightChild()
{
    return this->rightChild;
}

Token** Token::getRightChildAddr() {
	return &(this->rightChild);
}

void Token::setLineNumber(string s)
{
    this->lineNumber = this->lineNumber + "\t\t" + s;
}
string Token::getLineNumber()
{
    return this->lineNumber;
}
