/*
 * Inputparser.h
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#ifndef INPUTPARSER_H_
#define INPUTPARSER_H_

#include <bits/stdc++.h>

using namespace std;

class Input_parser {
public:
	Input_parser();
	virtual ~Input_parser();

	//Take the rule as string and returns it as a
	//map of rule name(string) and expressions(set<string>)
	map<string, set<string>> get_rules_map(vector<string> rules);

	//remove spaces for given string
	string trim (string str);

};

#endif /* INPUTPARSER_H_ */
