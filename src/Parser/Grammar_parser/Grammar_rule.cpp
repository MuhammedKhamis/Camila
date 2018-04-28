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

			int counter = 0;
			for (it2 = new_rule.expressions.begin(); it2 != new_rule.expressions.end(); ++it2)
			{
				string temp = *it2;
				//if epsilon then ignore its concatenation
				if(!temp.compare("\\L ")){
					add_expression(append_expr);
				}else{
					//Concatenate then add to expressions
					temp.append(append_expr);
					add_expression(temp);
				}
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
			string without_space="";
			without_space.append(expr.begin(),expr.end()-1);
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
	string without_space="";
	without_space.append(expr.begin(),expr.end()-1);
	add_expression(expr);
}

void Grammar_rule::set_expression(set<string> expression){
	expressions = expression;
}

void Grammar_rule::print_rule(){
	std::set<string>::iterator it;

	cout<<non_terminal<<endl;

	for (it = expressions.begin(); it != expressions.end(); ++it)
	{
		cout<<*it<<endl;
	}
	cout<<endl;
}

string Grammar_rule::rule_to_string(){
	string result = "# ";

	result.append(non_terminal);

	result.append(" ::= ");

	std::set<string>::iterator it;

	for (it = expressions.begin(); it != expressions.end(); ++it)
	{
		string expr = *it;
		int n = expr.size();
		if(expr[n-1] != ' ')
			expr.append(" ");
		expr = remove_epsilon(expr);
		result.append(expr);
		result.append("| ");
	}
	//trim
	string without_space="";
    without_space.append(result.begin(), result.end()-3);
    result = without_space;
    return result;
}

string Grammar_rule::remove_epsilon(string expression){
	//contains only epsilon or doesn't contain epsilon
	if(expression.size() <= 3) return expression;

	string temp = expression;
	std::size_t found;
	found = temp.find("\\L");
	//if found
	if(found != std::string::npos){
		temp.replace(temp.find("\\L"),3,"");
	}
	return temp;
}
