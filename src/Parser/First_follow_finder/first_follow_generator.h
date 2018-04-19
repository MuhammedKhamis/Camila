/*
 * first_follow_generator.h
 *
 *  Created on: 19/4/2018
 *      Author: Murad
 */

#ifndef PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_
#define PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_

#include <vector>
#include <string>
#include <map>
#include "first_finder.h"
#include "follow_finder.h"

/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminals
 */
map<string, vector<string>> first_of_productions;
/**
 * map all non_terminal (or maybe used as terminal) string name which used as a key
 * values are a list of all firsts terminals
 */
map<string, vector<string>> follow_of_productions;

class first_follow_generator{
public:
	vector<string> generate_first(string prod);
	vector<string> generate_follow(string prod);
	void generate_first_productions();
	void generate_follow_productions();
	void generate_first();
};

#endif /* PARSER_FIRST_FOLLOW_FINDER_FIRST_FOLLOW_GENERATOR_H_ */
