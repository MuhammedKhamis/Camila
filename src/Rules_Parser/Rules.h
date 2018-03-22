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

class Rules {
public:
	/*
	 * vector of order to select which vector should be popped from next
	 */
	std::vector<int> order;
	/*
	 * vector of keywords extracted from rules file.
	 */
	std::vector<std::vector<std::string>> keywords;
	/*
	 * vector of punctuation extracted from rules file.
	 */
	std::vector<std::vector<std::string>> punctuations;
	/*
	 * vector of definitions extracted from rules file.
	 */
	std::vector<std::vector<std::string>> definitions;
	/*
	 * vector of expressions extracted from rules file.
	 */
	std::vector<std::vector<std::string>> expressions;

};

#endif /* RULES_H_ */
