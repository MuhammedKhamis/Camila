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
#include "Group.h"
#include "../Machines/Transition_Table.h"
#include "../Machines/State.h"
#include "../General/Enums.h"
#include "../Data_Structure/Token_Saver.h"

using namespace std;

class Minimizer {
public:

	Minimizer(Transition_Table* table);

	/**
	 * this function stop when it became stable
	 * it became stable when there is more nodes must to be split to another group
	 * division done based on the given list of input
	 */
	//void minimize(vector<char> inputs);

	/**
	 * dividing the groups into subgroups based on given input
	 * division done based on comparisons what's next of current node
	 * using the table of DFA
	 * return false when there is at least one division occurred, true otherwise
	 */
	//bool sub_minimize(char input);

	/**
	 * extract the minimized table
	 */
	//std::unordered_map<int, std::unordered_map<char, int>> build_minimized_table(vector<char> inputs);

	/**
	 * renaming next states
	 */
	//std::unordered_map<char, int> renaming_next_states(int node, vector<char> inputs);

	/**
	 * sequnce of minimization
	 * minimize, rename then return minimized table
	 */
	//unordered_map<int,unordered_map<char, int>> get_minimzed();

	Transition_Table* get_minimized();

private:
	/**
	 * instance of Groups class
	 */
	Groups gs;

	/**
	 * table of DFA
	 */
	Transition_Table* t_table;

	unordered_map<int,unordered_map<string,int>> table;

	Token_Saver& saver = Token_Saver::get_Instance();

	State* start_state;

	void get_highest(priority& p , string& token,int i);

	void construction();

	bool same_group(int first , int second);

	bool identical_groups(Groups g1, Groups g2);

	bool identical_group(Group g1 , Group g2);

	Transition_Table* make_minimized_table();

};



#endif /* MINIMIZER_H_ */
