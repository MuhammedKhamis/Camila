/*
 * Transition_Table_Builder.cpp
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */



#include "Transition_Table_Builder.h"

static Transition_Table_Builder* Transition_Table_Builder::get_Instance(){

	if(this->t_builder == 0){
		t_builder = new Transition_Table_Builder;
	}
	return t_builder;
}

Machine* Transition_Table_Builder::generate_defination_NFA(Graph* g){
	//TODO
	return 0;
}
