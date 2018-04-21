/*
 * Grammar_rule.h
 *
 *  Created on: Apr 21, 2018
 *      Author: mishors
 */

#ifndef GRAMMAR_RULE_H_
#define GRAMMAR_RULE_H_

#include <bits/stdc++.h>

using namespace std;

class Grammar_rule {
public:
	Grammar_rule();
	virtual ~Grammar_rule();

	string non_terminal;
	set<string> expressions;

	/* Set the productions rule data by tokenizing
	 * the input_rule string
	 */
	void set_rule(string input_rule);

	/*
	 * Insert new alternative expression to the production rule
	 */
	void add_expression(string expr);

	/*
	 *	set non_terminal (name) of the production rule
	 */
	void set_non_terminal(string value);

	/*
	 *	get non_terminal (name) of the production rule
	 */
	string get_non_terminal();

	/*
	 *	returns set of alternative expressions
	 *	of the production rules
	 */
	set<string> get_expressions();

};

#endif /* GRAMMAR_RULE_H_ */
