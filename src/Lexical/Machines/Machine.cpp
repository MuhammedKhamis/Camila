/*
 * Machine.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: muhammed
 */


#include "Machine.h"

Machine::Machine(Transition_Table *table){
	this->table = table;
}
 State* Machine::get_current(){
	 return table->current_state();
 }
 State* Machine::get_start(){
	 return table->get_start_state();
 }
 bool Machine::next(State* current, string input){
	 int current_id = current->get_id();
	 State* next = table->get_next_state(current_id,input);
	 if(next == 0){
		 return false;
	 }
	 return true;
 }

