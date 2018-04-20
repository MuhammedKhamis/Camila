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
#include "first_finder.h"

const string eps = "\'eps\'";

using namespace std;

void first_follow_generator::add_to_productions(string lhs, set<string> prods) {
	// implement of adding lhs and prods
}

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

bool first_finder(string lhs, string rhs) {
	//check if x is terminal
	if (lhs.at(0) == '\'') {
		vector<string> v { explode(lhs, ' ') };
		return v[0];
	} else if (lhs == eps) {
		first_of_productions[lhs].insert(eps);
	}else{
		vector<string> v { explode(x, ' ') };
		for (int i = 0; i < v.size(); ++i) {
			first_of_productions[x]
		}
	}
}
//
//void first_follow_generator::generate_first_productions() {
//	for (map<string, set<string>>::iterator it = productions.begin();
//			it != productions.end(); ++it) {
//		for (set<string>::iterator e = (*it).second.begin();
//				e != (*it).second.end(); ++e) {
//			string s = (*e);
//			vector<string> v { explode(s, ' ') };
//			bool b = false;
//			int i = 0;
//			for (i = 0; i < v.size(); ++i) {
//				//find_first and return boolean to b
//				if (!b) {
//					break;
//				}
//			}
//			if (b && i = v.size()) {
//				// add eps
//			}
//
//		}
//
//	}
//}

void first_follow_generator::generate_first_productions() {

	//pass one
	//add all eps and terminals when x is eps or terminal directly
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		for (set<string>::iterator sub_p_it = (*p_it).second.begin();
				sub_p_it != (*p_it).second.end(); ++sub_p_it) {
			if ((*sub_p_it) == eps) {
				first_of_productions[(*p_it).first].insert(eps);
			} else if ((*sub_p_it)[0] == '\'') {
				vector<string> v { explode(*sub_p_it, ' ') };
				first_of_productions[(*p_it).first].insert(v[0]);
			}
		}
	}

//	pass two
//	recurse to add non-terminals when x is a non-terminal
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		for (set<string>::iterator sub_p_it = (*p_it).second.begin();
				sub_p_it != (*p_it).second.end(); ++sub_p_it) {
			if ((*sub_p_it) != eps && (*sub_p_it)[0] != '\'') {
				vector<string> v { explode(*sub_p_it, ' ') };

			}
		}
	}
}
