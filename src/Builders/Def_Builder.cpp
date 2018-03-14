/*
 * Def_Builder.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#include "Def_Builder.h"


static Def_Builder* Def_Builder::get_Instance(){

	if(this->instance == 0){
		instance = new Def_Builder;
	}
	this->t_builder = Transition_Table_Builder::get_Instance();
	return instance;
}

Machine* Def_Builder::evaluate_def(vector<string> definations){
	// generate the graph for the defination
	Graph* g = generate_graph(definations[defination_index]);
	// generate the nfa table of the graph
	Machine* m = t_builder->generate_defination_NFA(g);
	// return the nfa
	return m;
}


Machine* Def_Builder::get_defination_machine(string name){
	//TODO
	return 0;
}


Graph* Def_Builder::generate_graph(string line){
	//TODO
	return 0;
}


