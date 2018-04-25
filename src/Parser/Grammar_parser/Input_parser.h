/*
 * Inputparser.h
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#ifndef INPUTPARSER_H_
#define INPUTPARSER_H_

#include <bits/stdc++.h>
#include "../Data_Structures/Non_Terminal/non_terminal.h"

using namespace std;

class Input_parser {
public:
	Input_parser();
	virtual ~Input_parser();

	//Take the rule as string and returns it as a
	//map of rule name(string) and expressions(set<string>)
	map<string, set<string>> get_rules_map(vector<string> rules);

	vector<Non_Terminal> get_non_Terminals();

	//remove spaces for given string
	string trim (string str);

private:
	vector<Non_Terminal> non_terminals;

};

#endif /* INPUTPARSER_H_ */
