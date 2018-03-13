/*
 * Parser.cpp
 *
 *  Created on: 13/3/2018
 *      Author: Murad
 */

#include <iostream>
#include <string.h>
#include "Parser.h"
#include "Token.h"

using namespace std;

Token token;

int idx = 0;
char* stmt;

char* Parser::extract_name() {
	char* name = (char*) malloc(31);
	while (stmt[idx] != '\0' && stmt[idx] != '=' && stmt[idx] != ':') {
		name[idx] = stmt[idx];
		idx++;
	}
	name[idx] = '\0';
	return name;
};

char* Parser::extract_name() {
	char type;
	while(stmt[idx] == ' ' && idx++);
	type = stmt[idx++] = '=' ? '=' : ':';
	return type;
};

char** Parser::extract_tokens(){
	  char* t;
	  t = strtok(stmt," |");
	  while (t != NULL)
	  {
	    printf ("%s\n",t);
	    t = strtok (NULL, " |");
	  }
	  return t;
}

Token Parser::parse(){

}

