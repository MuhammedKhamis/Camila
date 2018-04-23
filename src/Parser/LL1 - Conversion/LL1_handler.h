/*
 * LL1handler.h
 *
 *  Created on: Apr 21, 2018
 *      Author: Mohamed Raafat
 */

#ifndef LL1HANDLER_H_
#define LL1HANDLER_H_

#include "Parser/Grammar_parser/Grammar_rule.h"
#include <bits/stdc++.h>

using namespace std;

class LL1_handler {
public:
	LL1_handler();
	virtual ~LL1_handler();

	/*
	 *	Returns true if the production is LL(1)
	 *	false otherwise
	 */
	bool is_ll1 (Grammar_rule g);

	/*
	 *	Convert the input production grammar rule to LL(1)
	 *	and returns vector of the converted grammar rules
	 */
	vector<Grammar_rule> convert_to_ll1(vector<Grammar_rule> prod);

	/*
	 *	Returns vector of new grammar rules after elimination
	 *	of left recursion
	 */
	vector<Grammar_rule> eliminate_left_recursion(vector<Grammar_rule> rules);

	vector<Grammar_rule> eliminate_immediate_recursion(Grammar_rule rule);

	void split(Grammar_rule rule, Grammar_rule* contains, Grammar_rule* not_contains);

	void left_factor(Grammar_rule rule ,vector<Grammar_rule>* result);

	/*
	 *	Count number of unique starting elements of all expressions of the production rule
	 *	also counts the frequency of each starting symbol to help in left factoring
	 */
	void get_start_symbols(Grammar_rule rule, set<string>* start_symbols, map<string,int>* freq);
};

#endif /* LL1HANDLER_H_ */
