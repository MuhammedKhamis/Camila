/*
 * first_follow_generator.h
 *
 *  Created on: 19/4/2018
 *      Author: Murad
 */

#ifndef PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_
#define PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_

#include <set>
#include <string>
#include <map>

using namespace std;


/**
 * constant value for epsilon
 * we consider epsilon is referred to by eps
 */
const string eps = "\'eps\'";
/**
 * this status used by some functions to take certain action
 * this action is to continue in extraction from the next non terminal or not
 * it's set or reset after each call of those function
 */
bool status = false;

/**
 * productions which we work on.
 */
map<string, set<string>> productions;

/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminals
 */
map<string, set<string>> first_of_productions;
/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminals
 */
map<string, set<string>> follow_of_productions;

class first_follow_generator{
public:
	/**
	 * generate first of all productions
	 * this reset the two first_of_productions and follow_of_productions
	 * then run all production rules
	 * finally set the two maps again
	 * it's working by recursion, and use releasing technique
	 * and dynamic programming algorithm to enhance the operations
	 */
	void generate_first_productions();

	/*
	 *	to be explained....
	 */
	void generate_follow_productions();
	/**
	 * add a new production to our list of productions
	 * let prod is x->y1 | y2y3
	 * so lhs = x
	 * and prods = [y1, y2y3]
	 */
	void add_to_productions(string lhs, set<string> prods);

	/**
	 * it first reset
	 * then call for first and follow generator
	 */
	void generator();
};

#endif /* PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_ */
