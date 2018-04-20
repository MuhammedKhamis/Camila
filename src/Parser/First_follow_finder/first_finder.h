/*
 * first_finder.h
 *
 *  Created on: 19/4/2018
 *      Author: Murad
 */

#ifndef PARSER_FIRST_FOLLOW_FINDER_FIRST_FINDER_H_
#define PARSER_FIRST_FOLLOW_FINDER_FIRST_FINDER_H_

#include <set>
#include <string>

using namespace std;

class First_finder{

public:
	/**
	 * input is the x
	 * find the first of x
	 * return a set of terminals results
	 */
	set<string> find_first(string x);

};



#endif /* PARSER_FIRST_FOLLOW_FINDER_FIRST_FINDER_H_ */
