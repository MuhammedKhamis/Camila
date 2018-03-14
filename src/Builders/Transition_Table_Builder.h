/*
 * Transition_Table_Builder.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef TRANSITION_TABLE_BUILDER_H_
#define TRANSITION_TABLE_BUILDER_H_

#include <bits/stdc++.h>

using namespace std;


class Transition_Table_Builder{

public:
	static Transition_Table_Builder* get_Instance();
	Machine* generate_defination_NFA(Graph* g);

protected:

private:
	static Transition_Table_Builder* t_builder = 0;
	int sz = 0;
	map<string, int> definations_names;
	vector<Machine*> definations_NFAs;
};



#endif /* TRANSITION_TABLE_BUILDER_H_ */
