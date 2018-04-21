/*
 * Grammar_rule.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: Mohamed Raafat
 */

#include "Grammar_rule.h"



Grammar_rule::Grammar_rule() {
	// TODO Auto-generated constructor stub

}

Grammar_rule::~Grammar_rule() {
	// TODO Auto-generated destructor stub
}

void Grammar_rule::add_expression(string expr){
	expressions.insert(expr);
}

void Grammar_rule::set_non_terminal(string value){
	non_terminal = value;
}

string Grammar_rule::get_non_terminal(){
	return non_terminal;
}

set<string> Grammar_rule::get_expressions(){
	return expressions;
}

void Grammar_rule::set_rule(string input_rule){
	// stringstream class convert
	stringstream rule_stream(input_rule);

	string token;

	//Reading '#' character which indicates start of the rule
	getline(rule_stream, token, ' ');

	//If first token is not production rule returns
	if(token.compare("#") )return;

	//Reading the non_terminal (name) of the rule
	getline(rule_stream, token, ' ');

	set_non_terminal(token);

	//Read "::=" symbol
	getline(rule_stream, token, ' ');

	//If after production name there is no "::=" symbol means error;
	if(token.compare("::=")) return;

	//temp buffer to append expression tokens
	string expr = "";
	// Tokenizing w.r.t. space ' '
	while(getline(rule_stream, token, ' '))
	{
		//if end of expression by '|' operation push to expressions
		if(!token.compare("|")){
			//Add new expression to the production rule
			add_expression(expr);
			expr = "";
		}else {
			//Construct the expression
			expr.append(token);
			expr.append(" ");
		}
	}
	add_expression(expr);
}

