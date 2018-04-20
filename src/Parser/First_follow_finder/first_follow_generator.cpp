/*
 * first_follow_generator.cpp
 *
 *  Created on: 19/4/2018
 *      Author: Murad
 */

#include <map>
#include <set>
#include <string>
#include <vector>
#include "first_follow_generator.h"

using namespace std;

/**
 * this function is used to add a new production to the saved list of productions
 */
void first_follow_generator::add_to_productions(string lhs, set<string> prods) {
	productions[lhs].insert(prods.begin(), prods.end());
}

/**
 * the source code of this function is quoted from:
 * http://www.cplusplus.com/articles/2wA0RXSz/
 */
const vector<string> explode(const string& s, const char& c) {
	string buff { "" };
	vector<string> v;
	for (auto n : s) {
		if (n != c)
			buff += n;
		else if (n == c && buff != "") {
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);
	return v;
}

/**
 * clear or structures
 */
void clear_all_firsts_follows(){
	first_of_productions.clear();
	follow_of_productions.clear();
}

/**
 *
 * input is the lhs
 * find the first of lhs
 * this function depends on the productions and first_of_productions structures
 * which they are accessible by it
 */
set<string> first_finder(string lhs) {
	set<string> res;	//the result of this call
	if (lhs == eps) {	//check for epsilon
		res.insert(eps);
	} else if (lhs.at(0) == '\'') {	//check for terminals
		vector<string> v { explode(lhs, ' ') };
		res.insert(v[0]);
	} else {
		// check first if it is calculated before
		// dynamic programming algorithm is used
		if (!first_of_productions[lhs].empty()) {
			return first_of_productions[lhs];
		}
		// if it is not calculated, calculate it !
		for (set<string>::iterator sub_p_it = productions[lhs].begin();
				sub_p_it != productions[lhs].end(); ++sub_p_it) {
			vector<string> v { explode((*sub_p_it), ' ') };
			for (unsigned int i = 0; i < v.size() && status; ++i) {
				set<string> temp = first_finder(v[i]);
				if (temp.find(eps) != temp.end() && temp.size() > 1) {
					temp.erase(eps);
					status = true;	//means to look for the next non-terminal
				} else {
					status = false;		//means that that is sufficient
				}
				first_of_productions[lhs].insert(temp.begin(), temp.end());
			}
			if (status) {
				first_of_productions[lhs].insert(eps);
			}
		}
		return first_of_productions[lhs];
	}
	return res;
}

void first_follow_generator::generate_first_productions() {
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		if (first_of_productions[(*p_it).first].empty()) {
			first_finder((*p_it).first);
		}
	}
}

/**
 * to be commented..
 */
set<string> follow_finder(string lhs) {
	set<string> res;
	// to be implemented
	return res;
}

/**
 * to be commented..
 */
void first_follow_generator::generate_follow_productions(){
	// to be implemented
}


void first_follow_generator::generator() {
	//first reset all calculated firsts and follows
	clear_all_firsts_follows();
	//call generate_first_productions to generate all firsts of our list of rules
	generate_first_productions();
	//call generate_follow_productions to generate all follows of our list of rules
	generate_follow_productions();
}
