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

vector<Grammar_rule> LL1_handler::eliminate_immediate_recursion(Grammar_rule rule){

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
