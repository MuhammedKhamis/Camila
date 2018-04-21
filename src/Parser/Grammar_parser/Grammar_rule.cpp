/*
 * Grammar_rule.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: Mohamed Raafat
 */

#include "Grammar_rule.h"



Grammar_rule::Grammar_rule() {
	//  Auto-generated constructor stub

}

Grammar_rule::~Grammar_rule() {
	//  Auto-generated destructor stub
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

void Grammar_rule::append_to_expressions(string append_part){
	std::set<string>::iterator it;

	set<string> loop_set = expressions;

	expressions.clear();

	for (it = loop_set.begin(); it != loop_set.end(); ++it)
	{
		string temp = *it;
		temp.append(append_part);
		add_expression(temp);
	}
}

void Grammar_rule::replace_with(Grammar_rule new_rule){
	string new_rule_name = new_rule.get_non_terminal();
	std::set<string>::iterator it;
	int last_size = expressions.size();
	for (it = expressions.begin(); it != expressions.end(); ++it)
	{
		if(last_size - expressions.size()){
			it = expressions.begin();
			last_size = expressions.size();
		}
		//String stream class convert
		stringstream rule_stream(*it);

		string token;

		//Reading the first word if it is the same of the new_rule_name then there is left recursion
		getline(rule_stream, token, ' ');

		string append_expr = "";

		//If left recursion
		if(!token.compare(new_rule_name))
		{
			while(getline(rule_stream, token, ' ')){
				append_expr.append(token);
				append_expr.append(" ");
			}

			//remove the old expression
			expressions.erase(it);

			std::set<string>::iterator it2;

			for (it2 = new_rule.expressions.begin(); it2 != new_rule.expressions.end(); ++it2)
			{
				string temp = *it2;
				temp.append(append_expr);
				add_expression(temp);
			}
		}

	}

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
			//ignore spaces
			if(token.compare(" "))
			{
				//Construct the expression
				expr.append(token);
				expr.append(" ");
			}
		}
	}
	add_expression(expr);
}


