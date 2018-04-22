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
#include <iostream>

using namespace std;

first_follow_generator::first_follow_generator(
		map<string, set<string>> productions) {
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		add_to_productions((*p_it).first, (*p_it).second);
	}
}

map<string, map<string, vector<string>>> first_follow_generator::get_firsts() {
	return first_of_productions;
}

map<string, set<string>> first_follow_generator::get_follows() {
	return follow_of_productions;
}

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
 * clear all structures
 */
void first_follow_generator::clear_all_firsts_follows() {
	first_of_productions.clear();
	follow_of_productions.clear();
}

void insert_into_firsts(map<string, vector<string>> res, string key,
		string v_key, vector<string> v_values) {
	for (unsigned int i = 0; i < v_values.size(); ++i) {
		res[key].push_back(v_values[i]);
	}
}


// bugs:
// it may be in returned values during recursion
map<string, vector<string>> first_follow_generator::first_finder(string lhs) {
	cout<<lhs<<'\n';
	map<string, vector<string>> res;	//the result of this call
	if (lhs == eps) {	//check for epsilon
		res[eps].push_back(eps);
	} else if (lhs.at(0) == '\'') {	//check for terminals
		vector<string> v { explode(lhs, ' ') };
		insert_into_firsts(res, lhs, v[0], v);
	} else {
		// check first if it is calculated before
		// dynamic programming algorithm is used
		if (!first_of_productions[lhs].empty()) {
			return first_of_productions[lhs];
		}
		// if it is not calculated, calculate it !
		for (set<string>::iterator sub_p_it = productions[lhs].begin();
				sub_p_it != productions[lhs].end(); ++sub_p_it) {
			cout<<"prod: "<<(*sub_p_it)<<'\n';
			vector<string> v { explode((*sub_p_it), ' ') };
//			print_vector(v);
//			cout<<v.size();
			for (unsigned int i = 0; i < v.size() && status; ++i) {
				cout<<"\nvec: "<<v[i]<<'\n';
				map<string, vector<string>> temp = first_finder(v[i]);
				print_map_vector(temp);
				if (temp.find(eps) != temp.end() && temp.size() > 1) {
					temp.erase(eps);
					status = true;	//means to look for the next non-terminal
				} else {
					status = false;		//means that that is sufficient
				}
				first_of_productions[lhs].insert(temp.begin(), temp.end());
			}
			if (status) {
				first_of_productions[lhs][eps].push_back(eps);
			}
		}
		return first_of_productions[lhs];
	}
	map<string, vector<string>> mv;
//	cout<<"returned map vector >>> ";
//	print_map_vector(mv);
	return mv;
}

void first_follow_generator::generate_first_productions() {
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		if (first_of_productions[(*p_it).first].empty()) {
			first_finder((*p_it).first);
		}
	}
}

//map<string, set<string>> first_follow_generator::follow_finder() {
//	map<string, set<string>> res;
//	for (map<string, set<string>>::iterator p_it = productions.begin();
//			p_it != productions.end(); ++p_it) {
//		for (set<string>::iterator sub_p_it =
//				productions[(*p_it).first].begin();
//				sub_p_it != productions[(*p_it).first].end(); ++sub_p_it) {
//			vector<string> v { explode((*sub_p_it), ' ') };
//			for (unsigned int i = 1; i < v.size() && status; ++i) {
//				if ((i + 1 < v.size())) {
//					follow_of_productions[v[i]].insert(		//if A -> aBb
//							first_of_productions[v[i + 1]].begin(),	//then add first(b)
//							first_of_productions[v[i + 1]].end());
//					if (follow_of_productions[v[i]].find(eps)
//							!= follow_of_productions[v[i]].end()) {	//if first(b) contains eps add follow(A)
//						follow_of_productions[v[i]].erase(eps);
//						res[v[i]].insert((*p_it).first);
//					}
//				} else {
//					res[v[i]].insert((*p_it).first);	//if A -> aB
//				}
//			}
//		}
//	}
//	return res;
//}

//void first_follow_generator::generate_follow_productions() {
//	//add $ to S lhs
//	follow_of_productions[(*productions.begin()).first].insert("$");
//	//call for follow_finder, it sets the firsts values and return a list of pointers
//	map<string, set<string>> ptrs = follow_finder();
//	for (map<string, set<string>>::iterator ptr_it = ptrs.begin();
//			ptr_it != ptrs.end(); ++ptr_it) {
//		for (set<string>::iterator sub_ptr_it = (*ptr_it).second.begin();
//				sub_ptr_it != (*ptr_it).second.end(); ++sub_ptr_it) {
//			follow_of_productions[(*ptr_it).first].insert(
//					follow_of_productions[(*sub_ptr_it)].begin(),
//					follow_of_productions[(*sub_ptr_it)].end());
//		}
//	}
//}

void first_follow_generator::generator() {
	//first reset all calculated firsts and follows
	clear_all_firsts_follows();
	//call generate_first_productions to generate all firsts of our list of rules
	generate_first_productions();
//	//call generate_follow_productions to generate all follows of our list of rules
//	generate_follow_productions();
}

void first_follow_generator::print_productions() {
	printf("*** productions ***");
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		printf("\n");
		cout << (*p_it).first << "::\t";
		for (set<string>::iterator sub_p_it =
				productions[(*p_it).first].begin();
				sub_p_it != productions[(*p_it).first].end(); ++sub_p_it) {
			cout << *sub_p_it << "\t";
		}
	}
}

void first_follow_generator::print_firsts() {
	printf("*** firsts ***");
	for (map<string, map<string, vector<string>>> ::iterator p_it = first_of_productions.begin();
	p_it != first_of_productions.end(); ++p_it) {
		printf("\n");
		cout << (*p_it).first << ":: ";
		for (map<string, vector<string>>::iterator sub_p_it = (*p_it).second.begin();
		sub_p_it != (*p_it).second.end(); ++sub_p_it) {
			cout << (*sub_p_it).first << ":[";
			for (unsigned int i = 0; i < (*sub_p_it).second.size(); ++i) {
				cout << (*sub_p_it).second[i] << " ";
			}
			cout<<"]  "<<endl;
		}
	}
}

void first_follow_generator::print_vector(vector<string> v){
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	printf("\n");
}

void first_follow_generator::print_map_vector(map<string, vector<string>> mv){
	for (map<string, vector<string>>::iterator sub_p_it = mv.begin();
	sub_p_it != mv.end(); ++sub_p_it) {
		cout << (*sub_p_it).first << ":[";
		for (unsigned int i = 0; i < (*sub_p_it).second.size(); ++i) {
			cout << (*sub_p_it).second[i] << " ";
		}
		cout<<"]  "<<endl;
	}
}


int main() {
	/*
	 E -> TE’
	 E’ -> +TE’ | eps
	 T -> FT’
	 T’ -> *FT’ | eps
	 F -> (E) | id

	 */
	map<string, set<string>> ms;
	set<string> s;
	s.clear();
	s.insert("T E`");
	ms["E"].insert(s.begin(), s.end());
	s.clear();
	s.insert("'+' T E`");
	s.insert("eps");
	ms["E`"].insert(s.begin(), s.end());
	s.clear();
	s.insert("F T`");
	ms["T"].insert(s.begin(), s.end());
	s.clear();
	s.insert("'*' F T`");
	s.insert("eps");
	ms["T`"].insert(s.begin(), s.end());
	s.clear();
	s.insert("'(' E ')'");
	s.insert("'id'");
	ms["F"].insert(s.begin(), s.end());
	first_follow_generator ffg(ms);
//	ffg.print_productions();
	ffg.generate_first_productions();
	ffg.print_firsts();

	return 0;
}
