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
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "first_follow_generator.h"

using namespace std;

vector<set<string>> cycles;
set<string> cycle_detector;

first_follow_generator::first_follow_generator(
		map<string, set<string>> productions, vector<string> order_of_prods) {
	order_of_productions.clear();
	order_of_productions.insert(order_of_productions.end(),
			order_of_prods.begin(), order_of_prods.end());
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

vector<string> first_follow_generator::get_orders() {
	return order_of_productions;
}

void first_follow_generator::add_to_productions(string lhs, set<string> prods) {
	productions[lhs].insert(prods.begin(), prods.end());
}

/**
 * the source code of this function is quoted from:
 * http://www.cplusplus.com/articles/2wA0RXSz/
 * this functions used to split a string based on 'c'
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

void first_follow_generator::clear_all_firsts_follows() {
	first_of_productions.clear();
	follow_of_productions.clear();
}

map<string, vector<string>> first_follow_generator::first_finder(string lhs) {
	map<string, vector<string>> res;	//the result of this call
	if (cycle_detector.find(lhs) != cycle_detector.end()) {
		cycles.emplace_back(cycle_detector.begin(), cycle_detector.end());
		cycle_detector.clear();
		return res;
	}
	cycle_detector.insert(lhs);
	// check first if it is calculated before
	if (!first_of_productions[lhs].empty()) {
		return first_of_productions[lhs];
	}
	// if it is not calculated, find it !
	for (set<string>::iterator sub_p_it = productions[lhs].begin();
			sub_p_it != productions[lhs].end(); ++sub_p_it) {
		vector<string> v { explode((*sub_p_it), ' ') };
		if (v[0].at(0) == '\'') {	//check for terminals
			res[v[0]].insert(res[v[0]].end(), v.begin(), v.end());
		} else if (v[0] == "\\L") {		//check if it's epsilon
			res["\\L"].push_back(v[0]);
		} else {	//it is non-terminal
			//stop is true when the current non-terminal doesn't contain epsilon
			bool stop = false;
			for (unsigned int i = 0; (i < v.size()) && !stop; ++i) {
				map<string, vector<string>> temp;
				temp.clear();
				if(v[i].at(0) == '\''){
					temp[v[i]].insert(temp[v[i]].end(), v.begin(), v.end());
				}else{
					temp = first_finder(v[i]);
					for (map<string, vector<string>>::iterator it = temp.begin(); it!=temp.end(); ++it) {
						(*it).second.clear();
						(*it).second.insert((*it).second.end(),v.begin(), v.end());
					}
				}
				if (temp.find("\\L") == temp.end()) {
					stop = true;
				} else {
					if (i == (v.size() - 1)) {
						temp.erase("\\L");
					}
				}
				res.insert(temp.begin(), temp.end());
			}
		}
	}
	first_of_productions[lhs].insert(res.begin(), res.end());
	cycle_detector.erase(lhs);
	return res;
}

void first_follow_generator::generate_first_productions() {
	cycles.clear();
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		cycle_detector.clear();
		if (first_of_productions[(*p_it).first].empty()) {
			first_finder((*p_it).first);
		}
	}
	//substitute from the cycles
	for (unsigned int i = 0; i < cycles.size(); ++i) {
		//find the elements of the group
		set<string>::iterator lhs = cycles[i].begin();
		for (set<string>::iterator to = cycles[i].begin();
				to != cycles[i].end(); ++to) {
			first_of_productions[(*lhs)].insert(
					first_of_productions[(*to)].begin(),
					first_of_productions[(*to)].end());
		}
		//set other member of group to the same values
		for (set<string>::iterator to = cycles[i].begin();
				to != cycles[i].end(); ++to) {
			first_of_productions[(*to)].insert(
					first_of_productions[(*lhs)].begin(),
					first_of_productions[(*lhs)].end());
		}
	}
}

/**
 * used to return the keys of a map as a set
 */
set<string> extract_keys(map<string, vector<string>> ters) {
	set<string> res;
	for (map<string, vector<string>>::iterator ptr = ters.begin();
			ptr != ters.end(); ++ptr) {
		res.insert((*ptr).first);
	}
	return res;
}

map<string, set<string>> first_follow_generator::follow_finder() {
	map<string, set<string>> res;
//add the first at end again to check for it in the last rules
	order_of_productions.push_back(order_of_productions[0]);
	for (unsigned int forward = 1; forward < order_of_productions.size();
			++forward) {	//go on step forward
		for (int backward = forward; backward >= 0; --backward) {//check the existence for 'forward' in the backward rules
			for (set<string>::iterator sub_p_it =
					productions[order_of_productions[backward]].begin();
					sub_p_it
							!= productions[order_of_productions[backward]].end();
					++sub_p_it) {	//find each sub-production (separated by |)
				vector<string> v { explode((*sub_p_it), ' ') };
				for (unsigned int i = 0; i < v.size(); ++i) {//check each sympol in the sub-production
					if (((v[0].at(0) == '\'') || (v[0] == "\\L"))
							&& (v[i] != order_of_productions[forward])) {
						continue;
					}
					if (((i + 1) < v.size())) {
						set<string> temp;
						temp.clear();
						if ((v[i + 1].at(0) == '\'')) {
							temp.insert(v[i + 1]);
						} else {
							temp = extract_keys(first_of_productions[v[i + 1]]);
						}
						follow_of_productions[v[i]].insert(temp.begin(),
								temp.end());
						if (follow_of_productions[v[i]].find("\\L")
								!= follow_of_productions[v[i]].end()) {	//if first(b) contains eps add follow(A)
							follow_of_productions[v[i]].erase("\\L");
							res[v[i]].insert(order_of_productions[backward]);
						}
					} else {
						res[v[i]].insert(order_of_productions[backward]);//if A -> aB
					}

				}
			}
		}
	}
	return res;
}

void first_follow_generator::generate_follow_productions() {
//add $ to S lhs
	follow_of_productions[(*productions.begin()).first].insert("'$'");
//call for follow_finder, it sets the firsts values and return a list of pointers
	map<string, set<string>> ptrs = follow_finder();
	for (unsigned int i = 0; i < order_of_productions.size(); i++) {
		for (set<string>::iterator ptr_it =
				ptrs[order_of_productions[i]].begin();
				ptr_it != ptrs[order_of_productions[i]].end(); ++ptr_it) {
			follow_of_productions[order_of_productions[i]].insert(
					follow_of_productions[(*ptr_it)].begin(),
					follow_of_productions[(*ptr_it)].end());
		}
	}

}

void first_follow_generator::generator() {
//first reset all calculated firsts and follows
	clear_all_firsts_follows();
//call generate_first_productions to generate all firsts of our list of rules
	generate_first_productions();
//call generate_follow_productions to generate all follows of our list of rules
	generate_follow_productions();
}

void first_follow_generator::print_productions() {
	print_msg("*** print productions ***", "");
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
	print_msg("*** print firsts ***", "");
	for (map<string, map<string, vector<string>>> ::iterator p_it = first_of_productions.begin();
	p_it != first_of_productions.end(); ++p_it) {
		cout << (*p_it).first << "::\n";
		print_map_vector((*p_it).second);
	}
}

void first_follow_generator::print_follows() {
	print_msg("*** print follows ***", "");
	print_map_set(follow_of_productions);
}

void first_follow_generator::print_vector(vector<string> v) {
	cout << '[';
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v[i] << ",";
	}
	cout << "]\n";
}

void first_follow_generator::print_set(set<string> s) {
	cout << '{';
	for (set<string>::iterator ss = s.begin(); ss != s.end(); ++ss) {
		cout << (*ss) << ",";
	}
	cout << "}\n";
}

void first_follow_generator::print_map_vector(map<string, vector<string>> mv) {
	for (map<string, vector<string>>::iterator my_mv = mv.begin();
			my_mv != mv.end(); ++my_mv) {
		cout << (*my_mv).first << ":";
		print_vector((*my_mv).second);
	}
}

void first_follow_generator::print_map_set(map<string, set<string>> ms) {
	for (map<string, set<string>>::iterator my_ms = ms.begin();
			my_ms != ms.end(); ++my_ms) {
		cout << (*my_ms).first << ":";
		print_set((*my_ms).second);
	}
}

void first_follow_generator::print_cycles() {
	print_msg("print cycles in first", "");
	for (vector<set<string>>::iterator my_vs = cycles.begin();
			my_vs != cycles.end(); ++my_vs) {
		print_set((*my_vs));
		cout << "\n";
	}
}

void first_follow_generator::print_msg(string msg, string par) {
	cout << "msg>>\n " << msg << par << endl;
}

//int main() {
//	/*
//	 # S ::= R T
//	 # R ::= 's' U R 'b' | \L
//	 # U ::= 'u' U | \L
//	 # V ::= 'v' V | \L
//	 # T ::= V 't' T | \L
//	 */
//	map<string, set<string>> ms;
//	vector<string> order_of_productions;
//	set<string> s;
//	s.clear();
//	s.insert("R T");
//	ms["S"].insert(s.begin(), s.end());
//	order_of_productions.push_back("S");
//	s.clear();
//	s.insert("'s' U R 'b'");
//	s.insert("\\L");
//	ms["R"].insert(s.begin(), s.end());
//	order_of_productions.push_back("R");
//	s.clear();
//	s.insert("'u' U");
//	s.insert("\\L");
//	ms["U"].insert(s.begin(), s.end());
//	order_of_productions.push_back("U");
//	s.clear();
//	s.insert("'v' V");
//	s.insert("\\L");
//	ms["V"].insert(s.begin(), s.end());
//	order_of_productions.push_back("V");
//	s.clear();
//	s.insert("V 't' T");
//	s.insert("\\L");
//	ms["T"].insert(s.begin(), s.end());
//	order_of_productions.push_back("T");
//
//	first_follow_generator ffg(ms, order_of_productions);
//	ffg.generator();
//	ffg.print_productions();
//	ffg.print_firsts();
//	ffg.print_follows();
//	ffg.print_cycles();
//	return 0;
//}
