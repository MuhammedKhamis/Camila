/*
 * LL1handler.h
 *
 *  Created on: Apr 21, 2018
 *      Author: mishors
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
};

#endif /* LL1HANDLER_H_ */
