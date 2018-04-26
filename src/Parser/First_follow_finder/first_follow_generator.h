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

class first_follow_generator {
public:

	/**
	 * pass the productions through constructor
	 * parameter two is the orderer of read productions
	 * read productions isn't keeping its order in map, so pass an order for your entered productions (�������� :D)
	 */
	first_follow_generator(map<string, set<string>> productions,
						   vector<string> order_of_prods);

	/**
	 * add a new production to our list of productions
	 * let prod is x->y1 | y2y3
	 * so lhs = x
	 * and prods = [y1, y2y3]
	 */
	void add_to_productions(string lhs, set<string> prods);

	/**
	 * getter for firsts
	 */
	map<string, map<string, vector<string>>> get_firsts();

	/**
	 * getter for follows
	 */
	map<string, set<string>> get_follows();

	/**
	 *
	 * input is the lhs
	 * find the first of lhs
	 * this function depends on the productions and first_of_productions structures
	 * which they are accessible by it
	 */
	map<string, vector<string>> first_finder(string lhs);

	/**
	 * generate first of all productions
	 * this reset the two first_of_productions and follow_of_productions
	 * then run all production rules
	 * finally set the two maps again
	 * it's working by recursion, and use releasing technique
	 * and dynamic programming to enhance the operations
	 */
	void generate_first_productions();

	/**
	 * this function iterate all productions
	 * add the first values of each relation
	 * and save the pointers in a map to be substituted at the end
	 * the pointers is built by serach in the above rules for the current LHS
	 * e.g
	 E -> T E`
	 E`-> + T E` | eps
	 T -> F T`
	 T`-> * F T` | eps
	 F -> ( E ) | id
	 search for follow of T in rules [T, E`, E]
	 search for follow of E` in rules [E`, E]
	 the first rule problem is handled
	 * the substitutions are made out of this function
	 * the substitutions are returned
	 *
	 */
	map<string, set<string>> follow_finder();

	/**
	 * first add $ to the start rule
	 * second call for follow_finder to add terminals by calculated first and return the relations
	 * third substitute with the relations obtained
	 */
	void generate_follow_productions();

	/**
	 * it first reset
	 * then call for first and follow generator
	 */
	void generator();

	/**
	 * empty first_of_productions and follow_of_productions structures
	 */
	void clear_all_firsts_follows();

	/**
	 * print the passed map
	 */
	void print_map_vector(map<string, vector<string>> mv);

	/**
	 * print current productions
	 */
	void print_productions();

	/**
	 * print the current first_of_productions
	 */
	void print_firsts();

	/**
	 * print the current follow_of_productions
	 */
	void print_follows();

	/**
	 * print any passed vector of strings
	 */
	void print_vector(vector<string> v);

	/**
	 * print any message with a parmeter at the end
	 */
	void print_msg(string msg, string par);

	/**
	 * print passed set of strings
	 */
	void print_set(set<string> s);


	/**
	 * print the passed map of string and set structue
	 */
	void print_map_set(map<string, set<string>> ms);

private:

/**
 * productions which we work on.
 */
	map<string, set<string>> productions;

/**
 * save the order of productions
 * e.g if A->B  B->C  C->D ....etc.
 * save orders as {A, B, C...etc}
 */
	vector<string> order_of_productions;

/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminal and the associated productions
 */
	map<string, map<string, vector<string>>> first_of_productions;

/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminals
 */
	map<string, set<string>> follow_of_productions;

};

#endif /* PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_ */
