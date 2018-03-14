/*
 * Def_Builder.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef DEF_BUILDER_H_
#define DEF_BUILDER_H_

#include <bits/stdc++.h>
#include "../Machines/Machine.h"
#include "Transition_Table_Builder.h"

using namespace std;


class Def_Builder{

public:

	static Def_Builder* get_Instance();
	Machine* evaluate_def(vector<string> defination);
	Machine* get_defination_machine(string name);

protected:


private:
	Def_Builder();
	~Def_Builder();
	Graph* generate_graph(string line);

	static Def_Builder* instance = 0;
	Transition_Table_Builder* t_builder;
	static const int defination_index = 3;


};



#endif /* DEF_BUILDER_H_ */
