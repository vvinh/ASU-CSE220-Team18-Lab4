#include "Btree.h"
#include <stdlib.h>
#include <string.h>

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

void Btree::insertNode(Token** ptr, string tokenString, Token* node,
		string pLineNum) {

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
			(**ptr).setLineNumber(pLineNum);
		} // end if

	} else { // tree is not empty

		// tree is not empty
		// data to insert is less than data in current node

		if (tokenString.compare((*ptr)->getTokenString()) < 0) {

			insertNode((*ptr)->getLeftChildAddr(), tokenString, node, pLineNum);

		} // end if

		// data to insert is greater than data in current node
		else if (tokenString.compare((*ptr)->getTokenString()) > 0) {
			insertNode((*ptr)->getRightChildAddr(), tokenString, node,
					pLineNum);

		} // end else if
		  // duplicate data value ignored
		else if (tokenString.compare((*ptr)->getTokenString()) == 0) {

			(*ptr)->setLineNumber(node->getLineNumber());

			//printf("%s", "ignore duplicate");
		} // end else

	} // end else

}

void Btree::inOrder(Token* ptr) {
	// if tree is not empty, then traverse
	if (ptr != NULL) {
		inOrder(ptr->getLeftChild());
		//printf("%s\n", ptr->getTokenString().c_str());
		printf("%s\t\t%s\n", ptr->getTokenString().c_str(),
				ptr->getLineNumber().c_str());

		inOrder(ptr->getRightChild());
	} // end if
} // end function inOrder

