/*
 * Parser.cpp
 *
 *  Created on: 13/3/2018
 *      Author: Murad
 */

#include "Rules.h"

#include <iostream>
#include <string>
#include <vector>

#include "RulesParser.h"

using namespace std;

int idx;
Rules rules;

Rules RulesParser::parse_lines(vector<string> lines) {
	for (idx = 0; idx < lines.size(); idx++) {
		string line = lines[idx];
		if (line.at(0) == '[') {	//Punctuation
			parse(rules,line,0);
		} else if (line.at(0) == '{') {	//keywords
			parse(rules,line,1);
		} else {
			while (idx++ && line.at(idx) != ':' && line.at(idx) != '=');
			if (line.at(idx) == '=') {	//definitions
				parse(rules,line,2);
			} else if (line.at(idx) == ':') {	//expressions
				parse(rules,line,3);
			}
		}
	}
	return rules;
}

void RulesParser::parse(Rules rules, string line, int priorities) {
	switch (priorities) {
	case 0:
		keywords_parser(rules, line);
		break;
	case 1:
		Punctuation_parser(rules, line);
		break;
	case 2:
		definitions_parser(rules, line);
		break;
	case 3:
		expressions_parser(rules, line);
		break;
	default:
		break;
	}
}

void RulesParser::keywords_parser(Rules rules, string line) {
	int size = line.length();
	vector<string> tokens;
	for (int i = 1; i < size - 1; i++) {
		string token;
		while (i < size && line[i] != ' ' && i++) {
			token.append(line.begin() + i, line.begin() + i + 1);
		}
		tokens.push_back(token);
		token.clear();
	}
	rules.keywords.push_back(tokens);
}

void RulesParser::Punctuation_parser(Rules rules, string line) {
	int size = line.length();
	vector<string> tokens;
	for (int i = 1; i < size - 1; i++) {
		string token;
		while (i < size && line[i] != ' ' && i++) {
			if (line[i] == '\\')
				continue;
			token.append(line.begin() + i, line.begin() + i + 1);
		}
		tokens.push_back(token);
		token.clear();
	}
	rules.punctuations.push_back(tokens);
}

void RulesParser::definitions_parser(Rules rules, string line) {
	vector<string> tokens = expr_def_parser(line);
	rules.definitions.push_back(tokens);
}

void RulesParser::expressions_parser(Rules rules, string line) {
	vector<string> tokens = expr_def_parser(line);
	rules.expressions.push_back(tokens);
}

vector<string> RulesParser::expr_def_parser(string line) {
	int size = line.length();
	vector<string> tokens;
	for (int i = 0; i < size; i++) {
		string token;
		while (i < size && i++) {
			if (line[i] == '\\' || line[i] == ' ')
				continue;
			if (line[i] == '|' || line[i] == '(' || line[i] == ')'
					|| line[i] == '+' || line[i] == '*' || line[i] == '-'
					|| line[i] == ':' || line[i] == '=') {
				tokens.push_back(token);
				token.clear();
				string sym(line.begin() + i, line.begin() + i + 1);
				tokens.push_back(sym);
			}
			token.append(line.begin() + i, line.begin() + i + 1);
		}
		tokens.push_back(token);
		token.clear();
	}
	return tokens;
}

//void Parser::extract_name(char stmt[]) {
//	char* name = (char*) malloc(31);
//	while (stmt[idx] != '\0' && stmt[idx] != '=' && stmt[idx] != ':') {
//		name[idx] = stmt[idx];
//		idx++;
//	}
//	cout<<name<<endl;
//	name[idx] = '\0';
//	tokens.push_back(name);
//}
//
//void Parser::extract_type(char stmt[]) {
//	char* type = (char*) malloc(2);
//	while (stmt[idx] == ' ' && idx++)
//		;
//
//	type[0] = stmt[idx++] == '=' ? '=' : ':';
//	type[1] = '\0';
//	cout<<type<<endl;
//
//	tokens.push_back(type);
//}
//
//void Parser::extract_tokens(char stmt[]) {
//	char * t = strtok(stmt, " :=");
//	t = strtok(NULL, " |=");
//	tokens.push_back(t);
//	while (t != NULL) {
//		t = strtok(NULL, " |");
//		tokens.push_back(t);
//	}
//}
//
//std::vector<char*> Parser::parse(vector) {
//	idx = 0;
//	tokens.clear();
////	int size = strlen(stmt)+1;
////	char stmt_cpy[size];
////	memcpy(stmt_cpy, stmt, size);
////	stmt_cpy[size] = '\0';
//	extract_name(stmt);
//	extract_type(stmt);
//	extract_tokens(stmt);
//	for (std::vector<char*>::iterator it = tokens.begin(); it != tokens.end();
//			++it)
//		std::cout << *it << '\n';
//	return tokens;
//}
//
