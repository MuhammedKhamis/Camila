/*
 * Postfixhandler.h
 *
 *  Created on: Mar 21, 2018
 *      Author: muhammed
 */

#ifndef POSTFIXHANDLER_H_
#define POSTFIXHANDLER_H_

#include <bits/stdc++.h>
#include "../Graph/Node.h"
#include "../Graph/Graph.h"
#include "../Builders/Thomson_Builder.h"

using namespace std;

class Postfix_handler {
public:
	/*
	 *  Singleton Class
	 */
		static Postfix_handler& get_Instance();

	/*
	 * convert infix expression to postfix expression
	 */
	vector<string> to_postfix(vector<string> exp);

	/*
	 * Takes postfix expression and evaluate its NFA and return the starting Node of NFA	 *
	 */
	Node* evaluate_postfix(vector<string> exp,string token);

private:
	/*
	 *  Singleton handling
	 */
	    Postfix_handler(){};
	    // Stop the compiler generating methods of copy the object
	    Postfix_handler(Postfix_handler const& copy);            // Not Implemented
	    Postfix_handler& operator=(Postfix_handler const& copy); // Not Implemented

	/*
	 * Check whether the operand is Letter or number
	*/
	bool is_operand(string c);

	/*
	 * Returns the priority of each operation
	 */
	int priority(string c);

	bool is_normal_operator(string c);

	bool is_converted_operator(string c);

	string convert_operator(string c);
	string convert_operator_back(string c);

};

#endif /* POSTFIXHANDLER_H_ */
