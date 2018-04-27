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


using namespace std;

class Input_parser {
public:
	Input_parser();
	virtual ~Input_parser();

	//Convert rules taken from the input file as lines(strings) into vector
	//of grammar_rules
	vector<Grammar_rule> get_grammar_rules(vector<string> rules);
};

#endif /* INPUTPARSER_H_ */
