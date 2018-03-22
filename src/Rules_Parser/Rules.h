/*
 * Rules.h
 *
 *  Created on: 15/3/2018
 *      Author: Murad
 */

#ifndef RULES_H_
#define RULES_H_

#include <vector>
#include <string>
#include "../Builders/Builder.h"
#include "../Builders/Thomson_Builder.h"
#include "../Graph/Node.h"

using namespace std;

class Rules {

public:

	Rules();

	void add_keyword(vector<string> keyword);

	void add_punctuations(vector<string> punc);

	void add_definitions(vector<string> def);

	void add_expressions(vector<string> exp);

	Node* parse_nfa();


private:
	/*
	 * vector of order to select which vector should be popped from next
	 */
	std::vector<int> order;

	int order_order;
	/*
	 * vector of keywords extracted from rules file.
	 */
	std::vector<std::vector<std::string>> keywords;

	int keywords_order;

	/*
	 * vector of punctuation extracted from rules file.
	 */
	std::vector<std::vector<std::string>> punctuations;

	int punctuations_order;

	/*
	 * vector of definitions extracted from rules file.
	 */
	std::vector<std::vector<std::string>> definitions;

	int definitions_order;

	/*
	 * vector of expressions extracted from rules file.
	 */
	std::vector<std::vector<std::string>> expressions;

	Builder& b = Builder::get_Instance();

	Thomson_Builder& t = Thomson_Builder::get_Instance();

	int expressions_order;

	 const int keyword_index = 0;
	 const int punctuations_index = 1;
	 const int definitions_index = 2;
	 const int expressions_index = 3;


};

#endif /* RULES_H_ */
