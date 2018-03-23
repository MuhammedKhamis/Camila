/*
 * Transition_Table.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: muhammed
 */

#include "Transition_Table.h"


Transition_Table::Transition_Table(unordered_map<int,unordered_map<string,int>> table){
	this->table = table;
	state_ids.resize(table.size());
	current_id = 0;
}

State* Transition_Table::get_next_state(int current,string input){
	if(table.find(current) == table.end()){
		return 0;
	}
	if(table[current].find(input) == table[current].end()){
		return 0;
	}
	if(table[current][input] >= state_ids.size()){
		return 0;
	}
	current_id =  table[current][input];
	return state_ids[current_id];
}

void Transition_Table::add_state(State *s){
	state_ids[s->get_id()] = s;
}

State* Transition_Table::current_state(){
	return state_ids[current_id];
}

State* Transition_Table::get_start_state(){
	return *state_ids.begin();
}

State* Transition_Table::get_state(int id){
	return state_ids[id];
}

void Transition_Table::print_table(){

	cout << "state count: " << state_ids.size() << endl;

	for(int i = 0 ; i < state_ids.size() ; i++){
		cout << "id: " << i << ", state: " << state_ids[i]->get_token();
		cout << endl;
	}

	for(auto it = table.begin() ; it != table.end() ; it++){

		int first = it->first;
		cout << "current state: " << first << endl;
		for(auto it1 = table[first].begin() ; it1 != table[first].end();it1++){
			cout << "input change: " << it1->first << ", next: " << it1->second << endl;
		}
		cout << " ---------------------- " << endl;

	}

}
unordered_map<int,unordered_map<string,int>> Transition_Table::get_table(){
	return table;
}

