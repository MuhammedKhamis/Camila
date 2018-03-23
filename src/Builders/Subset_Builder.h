/*
 * Subset_builder.h
 *
 *  Created on: Mar 19, 2018
 *      Author: muhammed
 */

#ifndef SUBSET_BUILDER_H_
#define SUBSET_BUILDER_H_

#include <bits/stdc++.h>
#include "../General/functions.h"
#include "../Graph/Node.h"
#include "../Data_Structure/Token_Saver.h"
#include "../Machines/Transition_Table.h"
#include "../General/Enums.h"
#include "../Machines/Machine.h"

using namespace std;

class Subset_Builder{

public:

	Subset_Builder();

	Transition_Table* convert_to_DFA(Node* start);

protected:


private:

	void bfs(Node* start);
	set<int> eps_closure(vector<int> start);
	int appeared_before(set<int> new_Dstate);

	Token_Saver& saver = Token_Saver::get_Instance();

	vector<vector<pair<string,int>>> adjList;

	unordered_map<int,string> token_table;

	unordered_map<int,set<int>> Dstates;




};



#endif /* SUBSET_BUILDER_H_ */
