/*
 * Inputparser.cpp
 * 		Parsing the raw input to be sent to first and follow
 *
 *  Created on: Apr 15, 2018
 *      Author: mishors
 */

#include "Input_parser.h"


Input_parser::Input_parser() {
	// TODO Auto-generated constructor stub

}

Input_parser::~Input_parser() {
	// TODO Auto-generated destructor stub
}

vector<Grammar_rule> Input_parser::get_grammar_rules(vector<string> rules){
	vector<Grammar_rule> result;
	for(int i=0; i<rules.size(); i++){
			Grammar_rule rule;
			rule.set_rule(rules[i]);
			result.push_back(rule);
		}
	return result;
}
