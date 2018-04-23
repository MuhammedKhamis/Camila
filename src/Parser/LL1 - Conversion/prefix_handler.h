/*
 * prefix_handler.h
 *
 *  Created on: Apr 23, 2018
 *      Author: Mohamed Raafat
 */

#ifndef PREFIX_HANDLER_H_
#define PREFIX_HANDLER_H_

#include <bits/stdc++.h>

using namespace std;

class prefix_handler {
public:
	prefix_handler();
	virtual ~prefix_handler();
	//At the end of processing it will contain sets of similar prefix expressions
	vector<set<string>> sets;

	// A Utility Function to find the common prefix between
	// strings- str1 and str2
	string commonPrefixUtil(string str1, string str2);

	//Checks whether they have common prefix or not
	bool has_common_prefix(string str1, string str2);

	//returns the union of 2 sets
	set<string> join (set<string> s1, set<string> s2);

	//find the common prefix of all the given set of strings
	string get_common_prefix(set<string> s);

	//generate sets of common prefix
	void generate_sets();

	//initialize the attribute (sets) with the given values
	void set_expressions(set<string> expressions);

	//print the contents of all sets
	void print_sets();

	//returns number of sets
	int get_sets_number();

	//returns number of rules should be created after left factoring
	int get_rules_number();

	//retrun sets values
	vector<set<string>> get_sets();

	//get the value of str after remove prefix from it
	//Hint: this function assumes that str has prefix of the input
	//and it doesn't check its value
	string get_remove_prefix(string str, string prefix);

	//returns the strings of the set after removing the longest
	//common prefix from them
	vector<string> get_set_remove_prefix(set<string> s);

};

#endif /* PREFIX_HANDLER_H_ */
