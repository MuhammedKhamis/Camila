/*
 * Parser.cpp
 *
 *  Created on: 13/3/2018
 *      Author: Murad
 */

#include "RulesParser.h"

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int idx;
std::vector<char*> tokens;

void Parser::extract_name(char stmt[]) {
	char* name = (char*) malloc(31);
	while (stmt[idx] != '\0' && stmt[idx] != '=' && stmt[idx] != ':') {
		name[idx] = stmt[idx];
		idx++;
	}
	cout<<name<<endl;
	name[idx] = '\0';
	tokens.push_back(name);
}

void Parser::extract_type(char stmt[]) {
	char* type = (char*) malloc(2);
	while (stmt[idx] == ' ' && idx++)
		;

	type[0] = stmt[idx++] == '=' ? '=' : ':';
	type[1] = '\0';
	cout<<type<<endl;

	tokens.push_back(type);
}

void Parser::extract_tokens(char stmt[]) {
	char * t = strtok(stmt, " :=");
	t = strtok(NULL, " |=");
	tokens.push_back(t);
	while (t != NULL) {
		t = strtok(NULL, " |");
		tokens.push_back(t);
	}
}

std::vector<char*> Parser::parse(char stmt[]) {
	idx = 0;
	tokens.clear();
//	int size = strlen(stmt)+1;
//	char stmt_cpy[size];
//	memcpy(stmt_cpy, stmt, size);
//	stmt_cpy[size] = '\0';
	extract_name(stmt);
	extract_type(stmt);
	extract_tokens(stmt);
	for (std::vector<char*>::iterator it = tokens.begin(); it != tokens.end();
			++it)
		std::cout << *it << '\n';
	return tokens;
}

