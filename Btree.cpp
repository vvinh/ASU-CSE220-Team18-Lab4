#include "Btree.h"
#include <stdlib.h>
#include <string.h>

const char* const SYMBOL_STRINGS[] = { "<no token>", "<IDENTIFIER>", "<NUMBER>",
		"<STRING>", "^", "*", "(", ")", "-", "+", "=", "[", "]", ":", ";", "<",
		">", ",", ".", "/", ":=", "<=", ">=", "<>", "..", "<END OF FILE>",
		"<ERROR>", "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO",
		"DOWNTO", "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
		"LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", "PROCEDURE",
		"PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE", "UNTIL",
		"VAR", "WHILE", "WITH", };

Btree::Btree(Token* rootPointer) {
	rootPtr = rootPointer;
}
Btree::~Btree() {

}

void Btree::setRootNode(Token* rootPointer) {
	rootPtr = rootPointer;
}

Token* Btree::getRootNode() {
	return rootPtr;
}

Token** Btree::getRootNodeAddr() {
	return &rootPtr;
}

void Btree::insertNode(Token** ptr, string tokenString, Token* node) {

	//tree is empty
	if (*ptr == NULL) {

		*ptr = new Token();

		// if memory was allocated, then assign data
		if (*ptr != NULL) {
			(**ptr).setCode(node->getCode());
			(**ptr).setType(node->getType());
			(**ptr).setTokenString(node->getTokenString());
			(**ptr).setLeftChild(NULL);
			(**ptr).setRightChild(NULL);
		} // end if

	} else { // tree is not empty

		// tree is not empty
		// data to insert is less than data in current node

		if (tokenString.compare((*ptr)->getTokenString()) < 0) {

			insertNode((*ptr)->getLeftChildAddr(), tokenString, node);

			//fflush(stdout);

		} // end if

		// data to insert is greater than data in current node
		else if (tokenString.compare((*ptr)->getTokenString()) > 0) {
			insertNode((*ptr)->getRightChildAddr(), tokenString, node);
			//fflush(stdout);
		} // end else if
		  // duplicate data value ignored
		else if (tokenString.compare((*ptr)->getTokenString()) == 0) {

			//printf("%s", "ignore duplicate");
		} // end else

	} // end else

}


void Btree::inOrder(Token* ptr) {
	// if tree is not empty, then traverse
	if (ptr != NULL) {
		inOrder(ptr->getLeftChild());
		printf("%s\n", ptr->getTokenString().c_str());
		inOrder(ptr->getRightChild());
	} // end if
} // end function inOrder


void Btree::preOrder(Token* ptr) {

	if (ptr != NULL) {
		printf("%s\n", ptr->getTokenString().c_str());
		preOrder(ptr->getLeftChild());
		preOrder(ptr->getRightChild());
	} // end if
} // end function preOrder

void Btree::postOrder(Token* ptr) {

	if (ptr != NULL) {
		postOrder(ptr->getLeftChild());
		postOrder(ptr->getRightChild());
		printf("%s\n", ptr->getTokenString().c_str());
	} // end if
} // end function postOrder




