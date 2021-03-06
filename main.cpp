//
//  main.cpp
//  Lab4
//
//  Created by Bryce Holton.
//

#include "Btree.h"
#include <iostream>
#include "common.h"
#include "Print.h"
#include "Scanner.h"
#include "Token.h"

#include <iomanip>
#include <locale>
#include <sstream>
#include <string> // this should be already included in <sstream>

FILE *init_lister(const char *name, char source_file_name[], char dte[]);
void quit_scanner(FILE *src_file, Token *list);
void add_token_to_list(Token *list, Token *new_token);

int main(int argc, const char * argv[]) {
	
	Token *token = NULL;
	char source_name[MAX_FILE_NAME_LENGTH];
	char date[DATE_STRING_LENGTH];
	FILE *source_file = init_lister(argv[1], source_name, date); // open source file
	Print print(source_name, date); //create Print object
	Scanner scanner(source_file, source_name, date, print); //create Scanner object
	Btree aBtree(NULL);  // create a binary tree
	do // continue as long as not a "period" or "end of file"
	{
		token = scanner.getToken(); //get a Token object
		//if is Identifier then add to binary tree
		if (token->getCode() == IDENTIFIER) {

			int lNumber = scanner.getLineNumber();
			ostringstream convert;   // stream used for the conversion
			convert << lNumber; // insert the textual representation of 'Number' in the characters in the stream
			string lineNumber = convert.str();

			aBtree.insertNode(aBtree.getRootNodeAddr(), token->getTokenString(),
					token, lineNumber);

		}
		print.printToken(token); // build a line then print the line
		fflush(stdout);
		if (token->getCode() != PERIOD && token->getCode() != END_OF_FILE) {
			delete token;  //Deallocate storage space
		}
	} while (token->getCode() != PERIOD && token->getCode() != END_OF_FILE);

	printf("\nCross Reference Information\n");

	printf("Identifier\t\tLine Numbers\n");

	printf("----------\t\t------------\n");

	aBtree.inOrder(aBtree.getRootNode());

	delete token;  //Deallocate storage space
	fclose(source_file);  //close the source file
	return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[]) {
	time_t timer;
	FILE *file;
	strcpy(source_file_name, name);
	file = fopen(source_file_name, "r");
	time(&timer);
	strcpy(dte, asctime(localtime(&timer)));
	return file;
}

