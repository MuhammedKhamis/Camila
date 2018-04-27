/*
 * LL1handler.cpp
 *
 *  Created on: Apr 21, 2018
 *      Author: Mohamed Raafat
 */

#include "LL1_handler.h"


LL1_handler::LL1_handler() {
	//  Auto-generated constructor stub

}

LL1_handler::~LL1_handler() {
	//  Auto-generated destructor stub
}

vector<Grammar_rule> LL1_handler::convert_to_ll1(vector<Grammar_rule> prod){
	vector<Grammar_rule> res,input;
	input = eliminate_left_recursion(prod);

	for(int i=0; i<input.size(); i++){
		bool factored = left_factor(input[i],&res);
		if(!factored)
			res.push_back(input[i]);
		}
	return res;
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

		str.append("`");

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

		//If size equals 1 it means that no immediate left recursion
		//so return the original rule
		if(contains.expressions.size() == 1)
		{
			result.push_back(rule);
		}else{
			result.push_back(contains);
			result.push_back(not_contains);
		}

		return result;
}

vector<Grammar_rule> LL1_handler::eliminate_left_recursion(vector<Grammar_rule> rules){
	vector<Grammar_rule> final_rules = rules;

	//Main_ loop to eliminate left recursion
	for(int i=0; i < rules.size(); i++){
		for(int j=0; j < i; j++){
			/*
			 * replace each production
			 * 		A[i] -> A[j] q
			 * 	with
			 * 		A[i] -> b1 q | b2 q | ... |bk q
			 * 	where
			 * 		A[j] -> b1 | b2 | ... | bk
			 */
			string curr_name = final_rules[i].get_non_terminal();

			//Check to not substitute the same rule to itself
			if(curr_name.compare(rules[j].get_non_terminal()))
				final_rules[i].replace_with(rules[j]);
		}
	}

	/** Call eliminate immediate left recursion and add them to final rules **/
	for(int i=0; i<final_rules.size(); i++)
	{

		Grammar_rule curr_rule = final_rules[i];

		vector<Grammar_rule> new_rules = eliminate_immediate_recursion(curr_rule);



		//Erase the rule because it will be converted after immediate left recursion elimination
		final_rules.erase(final_rules.begin() + i);

		if(new_rules.size() == 2){
			final_rules.insert(final_rules.begin()+i, new_rules[0]);
			final_rules.insert(final_rules.begin()+i, new_rules[1]);
			//to handle the index after insertion
			i++;
		}else{
			//No left recursion --> Add the original rule
			final_rules.insert(final_rules.begin() + i,rules[i]);
		}

	}


	return final_rules;
}

void LL1_handler::get_start_symbols(Grammar_rule rule, set<string>* start_symbols, map<string,int>* freq){

	std::set<string>::iterator it;

	for (it = rule.expressions.begin(); it != rule.expressions.end(); ++it)
	{
		//String stream class convert
		stringstream rule_stream(*it);

		string token;

		//Reading the first word if it is the same of the new_rule_name then there is left recursion
		getline(rule_stream, token, ' ');

		//if not found
		if(freq->find(token) == freq->end())
		{
			freq->insert(pair<string,int> (token,1));
		}
		else
	    {
			map<string,int> :: iterator itr = freq->find(token);
			itr->second++;
		}

		start_symbols->insert(token);

	}
	return;
}

bool LL1_handler::left_factor(Grammar_rule rule, vector<Grammar_rule> *result){

	//Get start symbols of of each expression in the production to check left factoring
	set<string> start_symbols;
	map<string,int> freq;
	get_start_symbols(rule, &start_symbols, &freq);

	//prefix_handler instance to handle prefix of expressions
	prefix_handler ph;

	//initialize the handler with the input expressions
	ph.set_expressions(rule.expressions);

	//classify the expressions into disjoint sets according to the longest common prefix
	ph.generate_sets();

	//If no left factoring return vector has the input production rule indicating not left factoring
	if(ph.get_sets_number() == rule.expressions.size()) {
		return false;
	}

	int number_of_rules = ph.get_rules_number();

	//Left factoring

	//intermediate result
	vector<Grammar_rule> temp_result;

	//Create empty rules
	for(int i=0; i<number_of_rules; i++){
		Grammar_rule prod;
		string name = rule.get_non_terminal();
		string extra_name = "`";
		for(int j=0; j<i; j++){
			name.append(extra_name);
		}
		prod.set_non_terminal(name);
		temp_result.push_back(prod);
	}

	vector<set<string>> disj_sets = ph.get_sets();

	int k=1;

	for(int i=0; i<disj_sets.size(); i++){
		set<string> curr_set = disj_sets[i];
		std::set<string>::iterator it;
		//if No common prefix
		if(curr_set.size() == 1){
			it = curr_set.begin();
			string expression = *it;
			//No factoring here
			temp_result[0].add_expression(expression);
		}else{
			//find the common prefix string of the current set
			string common_prefix = ph.get_common_prefix(curr_set);
			//Make the name of expression after left factoring
			//by concatenating the prefix to the new rule
			string expr_name = common_prefix;
			expr_name += " ";
			expr_name.append(temp_result[k].get_non_terminal());
			//add it after left factoring to the original rule
			temp_result[0].add_expression(expr_name);

			//get values of the current set after factoring the common prefix
			vector<string> expr_no_prefix = ph.get_set_remove_prefix(curr_set);
			for(int j=0; j<expr_no_prefix.size(); j++){
				temp_result[k].add_expression(expr_no_prefix[j]);
			}
			k++;
		}
	}

	for(int i=0; i<temp_result.size(); i++)
	{
		//Nested Left factoring
		bool Nested = left_factor(temp_result[i],result);
		//if NO Nested left factor happened add to total result
		if(!Nested)
			result->push_back(temp_result[i]);
	}
	return true;
}
