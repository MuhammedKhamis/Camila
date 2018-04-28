/*
 * Inputparser.h
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#ifndef INPUTPARSER_H_
#define INPUTPARSER_H_


#include "Grammar_rule.h"
#include <bits/stdc++.h>
#include "../Data_Structures/Non_Terminal/non_terminal.h"
#include "../Data_Structures/First_Follow_Package/FF_Package.h"

using namespace std;

class Input_parser {
public:
	Input_parser();
	virtual ~Input_parser();


	//Convert rules taken from the input file as lines(strings) into vector
	//of grammar_rules
	vector<Grammar_rule> get_grammar_rules(vector<string> rules);

	//Inverse of get_grammar_rules function
	vector<string> get_grammar_strings(vector<Grammar_rule> rules);

	//Take the rule as string and returns it as a
	//map of rule name(string) and expressions(set<string>)
	FF_Package get_rules_map(vector<string> rules);

	vector<Non_Terminal> get_non_Terminals();

	//remove spaces for given string
	string trim (string str);

private:
	vector<Non_Terminal> non_terminals;

};

#endif /* INPUTPARSER_H_ */
