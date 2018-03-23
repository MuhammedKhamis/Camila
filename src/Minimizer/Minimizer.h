/*
 * Minimizer.h
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#ifndef MINIMIZER_H_
#define MINIMIZER_H_

#include <bits/stdc++.h>
#include "Groups.h"
using namespace std;

class Minimizer {
public:

	Minimizer(Groups g, unordered_map<int,unordered_map<char,int>> table);

	/**
	 * this function stop when it became stable
	 * it became stable when there is more nodes must to be split to another group
	 * division done based on the given list of input
	 */
	void minimize(char inputs[]);

	/**
	 * dividing the groups into subgroups based on given input
	 * division done based on comparisons what's next of current node
	 * using the table of DFA
	 * return false when there is at least one division occurred, true otherwise
	 */
	bool sub_minimize(char input);

	/**
	 * extract the minimized table
	 */
	std::unordered_map<int, std::unordered_map<char, int>> build_minimized_table(char inputs[]);

	/**
	 * renaming next states
	 */
	std::unordered_map<char, int> renaming_next_states(int node, char inputs[]);

	/**
	 * sequnce of minimization
	 * minimize, rename then return minimized table
	 */
	std::unordered_map<char, int> get_minimzed(char inputs[]);


private:
	/**
	 * instance of Groups class
	 */
	Groups g;

	/**
	 * table of DFA
	 */
	std::unordered_map<int, std::unordered_map<char, int>> table;
};



#endif /* MINIMIZER_H_ */
