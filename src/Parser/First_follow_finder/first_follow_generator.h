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

<<<<<<< HEAD
/**
 * constant value for epsilon
 * we consider epsilon is referred to by eps
 */
const string eps = "\\L'";
/**
 * this status used by some functions to take certain action
 * this action is to continue in extraction from the next non terminal or not
 * it's set or reset after each call of those function
 */
bool status = true;

/**
 * productions which we work on.
 */
map<string, set<string>> productions;

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


vector<string> order_of_productions;

=======
>>>>>>> bd3c2b7c87f0a0bca43387441037535f2abb7e62
class first_follow_generator {
public:

	/**
	 * pass the productions through constructor
	 */
	first_follow_generator(map<string, set<string>> productions, vector<string> order_of_prods);

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
	 * and dynamic programming algorithm to enhance the operations
	 */
	void generate_first_productions();

	/**
	 * this function iterate all productions
	 * add the first values of each relation
	 * and save the pointers in a map to be substituted at the end
	 * the substitutions are made out of this function
	 * the substitutions are returned
	 */
	map<string, set<string>> follow_finder();

	/**
	 * first add $ to the start rule
	 * second call for follow_finder to add terminals by calculated first and return the relations
	 * third substitute with the relations obtained
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

	void print_productions();

	void clear_all_firsts_follows();

	void print_firsts();

	void print_follows();

	void print_map_vector(map<string, vector<string>> mv);

	void print_vector(vector<string> v);

	void print_msg(string msg, string par);

<<<<<<< HEAD

	void print_set(set<string> s) ;


	void print_map_set(map<string, set<string>> ms);
=======
private:

/**
 * constant value for epsilon
 * we consider epsilon is referred to by eps
 */
	const string eps = "\\L";
/**
 * this status used by some functions to take certain action
 * this action is to continue in extraction from the next non terminal or not
 * it's set or reset after each call of those function
 */
	bool status = true;

/**
 * productions which we work on.
 */
	map<string, set<string>> productions;

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
>>>>>>> bd3c2b7c87f0a0bca43387441037535f2abb7e62

};

#endif /* PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_ */
