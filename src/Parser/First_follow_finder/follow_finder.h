/*
 * follow_finder.h
 *
 *  Created on: 19/4/2018
 *      Author: Murad
 */

#ifndef PARSER_FIRST_FOLLOW_FINDER_FOLLOW_FINDER_H_
#define PARSER_FIRST_FOLLOW_FINDER_FOLLOW_FINDER_H_

#include <string.h>

using namespace std;

class First_finder{

public:
	/**
	 * input is the production name
	 * production name is referred to by its LHS non-terminal
	 * find the first of a production
	 * return a set of terminals results
	 */
	void find_follow(string p_name);

};

#endif /* PARSER_FIRST_FOLLOW_FINDER_FOLLOW_FINDER_H_ */
