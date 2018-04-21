/*
 * LL1handler.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: mishors
 */

#include "LL1_handler.h"


LL1_handler::LL1_handler() {
	//  Auto-generated constructor stub

}

LL1_handler::~LL1_handler() {
	//  Auto-generated destructor stub
}

void LL1_handler::split(Grammar_rule rule, Grammar_rule* contains, Grammar_rule* not_contains){
	std::set<string>::iterator it;
	string rule_name = rule.get_non_terminal();

	for (it = rule.expressions.begin(); it != rule.expressions.end(); ++it)
	{
		//String stream class convert
		stringstream rule_stream(*it);

		string token;

		//Reading the first word if it is the same of the rule_name then remove it
		getline(rule_stream, token, ' ');

		string curr_name = token;

		string append_expr = "";

		//remove space
		//getline(rule_stream, token, ' ');

		while(getline(rule_stream, token, ' ')){
			append_expr.append(token);
			append_expr.append(" ");
		}



		//If immediate left recursion remove recursion string then add to (contains rule)
		if(!curr_name.compare(rule_name))
		{
			contains->add_expression(append_expr);
		}else{
			curr_name.append(" ");
			curr_name.append(append_expr);
			not_contains->add_expression(curr_name);
		}
	}
}

vector<Grammar_rule> LL1_handler::eliminate_immediate_recursion(Grammar_rule rule){
		Grammar_rule contains,not_contains;

		not_contains.set_non_terminal(rule.get_non_terminal());

		string str = rule.get_non_terminal();

		str.append("_new");

		contains.set_non_terminal(str);

		//split the rule having left recursion into 2 rules
		split(rule, &contains,&not_contains);

		//step1: A -> B1 A_new | B2 A_new | ...

		not_contains.append_to_expressions(str);

		//step2: A_new -> alpha1 A_new | alpha2 A_new | ... | epsilon

		contains.append_to_expressions(str);
		//Add epsilon
		contains.add_expression("\\L");

		vector<Grammar_rule> result;

		result.push_back(contains);

		result.push_back(not_contains);

		return result;
}

vector<Grammar_rule> LL1_handler::eliminate_left_recursion(vector<Grammar_rule> rules){
	vector<Grammar_rule> final_rules;

	//Initializing the final_rules with the original values
	for(int i = 0; i < rules.size(); i++){
		final_rules.push_back(rules[i]);
	}

	//Main_ loop to eliminate left recursion
	for(int i=0; i < rules.size(); i++){
		for(int j=0; j < rules.size(); j++){
			/*
			 * replace each production
			 * 		A[i] -> A[j] q
			 * 	with
			 * 		A[i] -> b1 q | b2 q | ... |bk q
			 * 	where
			 * 		A[j] -> b1 | b2 | ... | bk
			 */
			final_rules[i].replace_with(rules[j]);
		}

		/** Call eliminate immediate left recursion and add them to final rules **/

		Grammar_rule curr_rule = final_rules[i];

		//Erase the rule because it will be converted after immediate left recursion elimination
		final_rules.erase(final_rules.begin() + i);

		vector<Grammar_rule> new_rules = eliminate_immediate_recursion(curr_rule);

		//Adding the new rules after elimination
		for(int k = 0; k < new_rules.size(); k++){
			final_rules.push_back(new_rules[k]);
		}
	}
	return final_rules;
}
