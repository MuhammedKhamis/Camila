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
#include <stdio.h>
#include <string.h>

using namespace std;

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

//void insert_into_firsts(map<string, vector<string>> res, string key,
//		string v_key, vector<string> v_values) {
//	for (unsigned int i = 0; i < v_values.size(); ++i) {
//		res[key].push_back(v_values[i]);
//	}
//}

// bugs:
// it may be in returned values during recursion
map<string, vector<string>> first_follow_generator::first_finder(string lhs) {
//	print_msg("entered first_finder with lhs= ", lhs);
	map<string, vector<string>> res;	//the result of this call
//	if (lhs == eps) {	//check for epsilon
//		res[eps].push_back(eps);
//	} else if (lhs.at(0) == '\'') {	//check for terminals
////		vector<string> v { explode(lhs, ' ') };
//		res[]
//	} else {
	// check first if it is calculated before
	// dynamic programming algorithm is used
	if (!first_of_productions[lhs].empty()) {
//		print_msg("return at ",lhs);
		return first_of_productions[lhs];
	}
	// if it is not calculated, calculate it !
	for (set<string>::iterator sub_p_it = productions[lhs].begin();
			sub_p_it != productions[lhs].end(); ++sub_p_it) {
		vector<string> v { explode((*sub_p_it), ' ') };
		if (v[0].at(0) == '\'') {	//check for terminals
//			print_msg("terminal: ", v[0]);
			res[v[0]].insert(res[v[0]].end(), v.begin(), v.end());
		} else if (v[0] == "\\L") {
			res["\\L"].push_back(v[0]);
		} else {
			bool stop = false;
			for (unsigned int i = 0; (i < v.size()) && !stop; ++i) {
				map<string, vector<string>> temp;
				temp.clear();
//				print_msg("lhs is :::::: ",lhs);
//				print_msg("v[i] is :::::: ",v[i]);
				temp = first_finder(v[i]);
//				print_msg(">>>>  print temp >> at lhs =", lhs);
//				print_map_vector(temp);
				if (temp.find("\\L") == temp.end() || temp["\\L"].empty()) {
					stop = true;
//					print_msg(">>>>  true stop at lhs =", lhs);
				} else {
					if (i == (v.size() - 1)) {
						temp.erase("\\L");
					}
				}
//				if (temp.find("\\L") != temp.end() && temp.size() > 1) {
//					temp.erase(eps);
//					status = true;	//means to look for the next non-terminal
//				} else {
//					status = false;		//means that that is sufficient
//				}
				res.insert(temp.begin(), temp.end());
			}
//			if (status) {
//				first_of_productions[lhs][eps].push_back(eps);
//			}
		}
	}
//		return first_of_productions[lhs];
//	}
//	print_msg("print result before return", "");
//	print_map_vector(res);
	first_of_productions[lhs].insert(res.begin(), res.end());
	return res;
}

void first_follow_generator::generate_first_productions() {
//	print_msg("entered generate_first_productions", "");
	for (map<string, set<string>>::iterator p_it = productions.begin();
			p_it != productions.end(); ++p_it) {
		if (first_of_productions[(*p_it).first].empty()) {
			first_finder((*p_it).first);
		}
	}
}

set<string> extract_keys(map<string, vector<string>> ters) {
	set<string> res;
	for (map<string, vector<string>>::iterator ptr = ters.begin();
			ptr != ters.end(); ++ptr) {
		res.insert((*ptr).first);
	}
	return res;
}

//map<string, set<string>> first_follow_generator::follow_finder() {
//	map<string, set<string>> res;
//	for (map<string, set<string>>::iterator p_it = productions.begin();
//			p_it != productions.end(); ++p_it) {
//		for (set<string>::iterator sub_p_it =
//				productions[(*p_it).first].begin();
//				sub_p_it != productions[(*p_it).first].end(); ++sub_p_it) {
//			vector<string> v { explode((*sub_p_it), ' ') };
////			print_msg("print vectors inside follow","");
////			print_vector(v);
//
//			for (unsigned int i = 0; i < v.size(); ++i) {
//				if ((v[0].at(0) == '\'') || (v[0] == "\\L")) {
//					continue;
//				}
//				if (((i + 1) < v.size())) {
//
//					set<string> temp = extract_keys(
//							first_of_productions[v[i + 1]]);
//					follow_of_productions[v[i]].insert(temp.begin(),
//							temp.end());
////					follow_of_productions[v[i]].insert(		//if A -> aBb
////							first_of_productions[v[i + 1]].begin(),	//then add first(b)
////							first_of_productions[v[i + 1]].end());
//					if (follow_of_productions[v[i]].find("\\L")
//							!= follow_of_productions[v[i]].end()) {	//if first(b) contains eps add follow(A)
//						follow_of_productions[v[i]].erase("\\L");
//						res[v[i]].insert((*p_it).first);
//					}
//				} else {
//					res[v[i]].insert((*p_it).first);	//if A -> aB
//				}
//
//			}
//		}
//	}
//	print_msg("print pointers in follow reture", "");
//	print_map_set(res);
//	return res;
//}

map<string, set<string>> first_follow_generator::follow_finder() {
	map<string, set<string>> res;
	order_of_productions.push_back(order_of_productions[0]);
	print_vector(order_of_productions);
	for (unsigned int forward = 1; forward < order_of_productions.size();
			++forward) {
		for (int backward = forward; backward >= 0; --backward) {
			for (set<string>::iterator sub_p_it =
					productions[order_of_productions[backward]].begin();
					sub_p_it
							!= productions[order_of_productions[backward]].end();
					++sub_p_it) {
				vector<string> v { explode((*sub_p_it), ' ') };
				for (unsigned int i = 0; i < v.size(); ++i) {
					if (((v[0].at(0) == '\'') || (v[0] == "\\L"))
							&& (v[i] != order_of_productions[forward])) {
						continue;
					}
					if (v[i] == order_of_productions[forward]) {
						cout << "\n>>>>>>>>>>>>>>>>>> found" << v[i];
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
//	for (map<string, set<string>>::iterator p_it = productions.begin();
//			p_it != productions.end(); ++p_it) {
//		cout << ((*p_it).first) << "::::\n";
//		for (map<string, set<string>>::reverse_iterator p_r_it = productions.rbegin();
//				p_r_it != productions.rend(); ++p_r_it) {
//			cout << (*p_r_it).first << "\n";
	//		for (set<string>::iterator sub_p_it =
	//				productions[(*p_it).first].begin();
	//				sub_p_it != productions[(*p_it).first].end(); ++sub_p_it) {
	//			vector<string> v { explode((*sub_p_it), ' ') };
	////			print_msg("print vectors inside follow","");
	////			print_vector(v);
	//
	//			for (unsigned int i = 0; i < v.size(); ++i) {
	//				if ((v[0].at(0) == '\'') || (v[0] == "\\L")) {
	//					continue;
	//				}
	//				if (((i + 1) < v.size())) {
	//
	//					set<string> temp = extract_keys(
	//							first_of_productions[v[i + 1]]);
	//					follow_of_productions[v[i]].insert(temp.begin(),
	//							temp.end());
	////					follow_of_productions[v[i]].insert(		//if A -> aBb
	////							first_of_productions[v[i + 1]].begin(),	//then add first(b)
	////							first_of_productions[v[i + 1]].end());
	//					if (follow_of_productions[v[i]].find("\\L")
	//							!= follow_of_productions[v[i]].end()) {	//if first(b) contains eps add follow(A)
	//						follow_of_productions[v[i]].erase("\\L");
	//						res[v[i]].insert((*p_it).first);
	//					}
	//				} else {
	//					res[v[i]].insert((*p_it).first);	//if A -> aB
	//				}
	//
	//			}
//		}
//	}
	print_msg("print pointers in follow reture", "");
	print_map_set(res);
	return res;
}

void first_follow_generator::generate_follow_productions() {
	//add $ to S lhs
	follow_of_productions[(*productions.begin()).first].insert("$");
	//call for follow_finder, it sets the firsts values and return a list of pointers
	map<string, set<string>> ptrs = follow_finder();
//	print_msg("print follows (based on terminals only)","");
//	print_follows();
	for (unsigned int i = 0; i < order_of_productions.size(); i++) {
//		cout<<order_of_productions[i]<<endl;
		for (set<string>::iterator ptr_it =
				ptrs[order_of_productions[i]].begin();
				ptr_it != ptrs[order_of_productions[i]].end(); ++ptr_it) {
//			cout<<*ptr_it<<" ";

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
//	//call generate_follow_productions to generate all follows of our list of rules
	generate_follow_productions();
}

void first_follow_generator::print_productions() {
//
//	print_msg("*** print productions ***", "");
//	for (map<string, set<string>>::iterator p_it = productions.begin();
//			p_it != productions.end(); ++p_it) {
//		printf("\n");
//		cout << (*p_it).first << "::\t";
//		for (set<string>::iterator sub_p_it =
//				productions[(*p_it).first].begin();
//				sub_p_it != productions[(*p_it).first].end(); ++sub_p_it) {
//			cout << *sub_p_it << "\t";
//		}
//	}
//
}

void first_follow_generator::print_firsts() {
	print_msg("*** print firsts ***", "");
	for (map<string, map<string, vector<string>>> ::iterator p_it = first_of_productions.begin();
	p_it != first_of_productions.end(); ++p_it) {
		cout << "\n\nNon Terminal : " <<(*p_it).first << "::\n";
		print_map_vector((*p_it).second);
	}
}

void first_follow_generator::print_follows() {
	print_msg("*** print follows ***", "");
	print_map_set(follow_of_productions);
}

void first_follow_generator::print_vector(vector<string> v) {
//	cout << '[';
//	for (unsigned int i = 0; i < v.size(); ++i) {
//		cout << v[i] << ",";
//	}
//	cout << "]\n";
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

void first_follow_generator::print_msg(string msg, string par) {
//	cout << "msg>> " << msg << par << endl;
}

<<<<<<< HEAD
int main() {
	/*
	 E -> T E`
	 E`-> + T E` | eps
	 T -> F T`
	 T`-> * F T` | eps
	 F -> ( E ) | id

	 */
	map<string, set<string>> ms;
	vector<string> order_of_productions;
	set<string> s;
	s.clear();
	s.insert("T E`");
	ms["E"].insert(s.begin(), s.end());
	order_of_productions.push_back("E");
//	s.clear();
//	s.insert("E` T`");
//	ms["G"].insert(s.begin(), s.end());
	s.clear();
	s.insert("'+' T E`");
	s.insert("\\L");
	ms["E`"].insert(s.begin(), s.end());
	order_of_productions.push_back("E`");
	s.clear();
	s.insert("F T`");
	ms["T"].insert(s.begin(), s.end());
	order_of_productions.push_back("T");
	s.clear();
	s.insert("'*' F T`");
	s.insert("\\L");
	ms["T`"].insert(s.begin(), s.end());
	order_of_productions.push_back("T`");
	s.clear();
	s.insert("'(' E ')'");
	s.insert("'id'");
	ms["F"].insert(s.begin(), s.end());
	order_of_productions.push_back("F");
	first_follow_generator ffg(ms, order_of_productions);
//	ffg.print_productions();
	ffg.generator();
//	ffg.print_msg(
//			"********** testing ************\n ******************************",
//			"");
	ffg.print_firsts();
	ffg.print_follows();
=======
//
//int main() {
//	/*
//	 E -> eps | TE`
//	 E` -> +TE` | eps
//	 T -> FT`
//	 T` -> *FT` | eps
//	 F -> (E) | id
//	 */
//	map<string, set<string>> ms;
//	set<string> s;
//	s.clear();
//	s.insert("\\L");
//	s.insert("T E`");
//	ms["E"].insert(s.begin(), s.end());
//	s.clear();
//	s.insert("E` T`");
//	ms["G"].insert(s.begin(), s.end());
//	s.clear();
//	s.insert("'+' T E`");
//	s.insert("\\L");
//	ms["E`"].insert(s.begin(), s.end());
//	s.clear();
//	s.insert("T` F");
//	ms["T"].insert(s.begin(), s.end());
//	s.clear();
//	s.insert("'*' F T`");
//	s.insert("\\L");
//	ms["T`"].insert(s.begin(), s.end());
//	s.clear();
//	s.insert("'(' E ')'");
//	s.insert("'id'");
//	ms["F"].insert(s.begin(), s.end());
//
//	first_follow_generator ffg(ms);
////	ffg.print_productions();
//	ffg.generate_first_productions();
//	ffg.print_msg(
//			"********** testing ************\n ******************************",
//			"");
//	ffg.print_firsts();
//
//	return 0;
//}
>>>>>>> bd3c2b7c87f0a0bca43387441037535f2abb7e62

