/*
 * Minimizer.cpp
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#include "Minimizer.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
/*
void Minimizer::minimize(vector<char> inputs ) {
	int size = inputs.size();
	bool unstable = true;
	while (unstable) {
		unstable = false;
		for (int c = 0; c < size; ++c) {
			unstable |= sub_minimize(inputs[c]);
		}
	}
}

bool Minimizer::sub_minimize(char input) {
	bool unstable = false, rep = true;
	while (rep) {
		rep = false;
		for (vector<Group>::iterator it = g.groups.begin();
				it != g.groups.end(); ++it) {
			Group group = g.groups.back();
			set<int>::iterator ptr = group.group.begin();
			int g_num = g.find_group(*ptr);
			Group g1, g2;
			g1.add(*ptr);
			ptr++;
			while (ptr != group.group.end()) {
				int g_num_temp = g.find_group(*ptr);
				if (g_num_temp == g_num) {
					g1.add(*ptr);
				} else {
					g2.add(*ptr);
				}
				ptr++;
			}
			g.groups.pop_back();
			g.add(g1);
			if (!g2.group.empty()) {
				unstable = true;
				rep = true;
				g.add(g2);
			}
		}
	}
	return unstable;
}

unordered_map<int, unordered_map<char, int>> Minimizer::build_minimized_table(
		vector<char> inputs) {
	std::unordered_map<int, std::unordered_map<char, int>> m_table;
	for (unsigned int g_idx = 0; g_idx < g.groups.size(); ++g_idx) {
		Group g_ptr = g.groups[g_idx];
		set<int>::iterator it = g_ptr.group.begin();
		int g_num = g.find_group(*it);
		unordered_map<char, int> next_states = renaming_next_states(*it,
				inputs);
		m_table[g_num] = next_states;
	}
	return m_table;
}

unordered_map<char, int> Minimizer::renaming_next_states(int node,
		vector<char> inputs) {
	unordered_map<char, int> next_states;
	int size = inputs.size();
	for (int c = 0; c < size; ++c) {
		int g_num = g.find_group(table[node][inputs[c]]);
		next_states[inputs[c]] = g_num;
	}
	return next_states;
}
*/
Minimizer::Minimizer(Transition_Table* table) {
	this->t_table = table;
	this->table = t_table->get_table();
	construction();
}

void Minimizer::construction(){

	Group accepted_group,non_accepted_group;

	for(auto it = table.begin() ; it != table.end();it++){

		int id = it->first;

		if(t_table->get_state(id)->get_priority() == valid){
			accepted_group.add(id);
		}else{
			non_accepted_group.add(id);
		}
	}
	gs.add(accepted_group);
	gs.add(non_accepted_group);
	start_state = t_table->get_start_state();
}

Transition_Table* Minimizer::get_minimized(){
	while(true){
		Groups new_gs;
		for(int i = 0 ; i < gs.groups_count() ; i++){
			Group g = gs.get_group(i);

			// loop n^2 to see every node with other node
			vector<pair<int,int>> pairs = g.get_pairs();
			for(unsigned int j = 0 ; j < pairs.size() ; j++){
				int g_id1 = new_gs.find_group(pairs[j].first);
				if(same_group(pairs[j].first,pairs[j].second)){
					// add to the group of first pair
					if(g_id1 == -1){
						Group new_g;
						new_g.add(pairs[j].first);
						new_g.add(pairs[j].second);
						new_gs.add(new_g);
					}else{
						new_gs.add_node_to_group(g_id1,pairs[j].second);
					}
				}else if(g_id1 == -1){
						Group new_g;
						new_g.add(pairs[j].first);
						new_gs.add(new_g);
				}
			}
		}
		// new group has been created;
		if(identical_groups(gs,new_gs)){
			break;
		}
		gs = new_gs;
		// if identical then break

	}
	// divided into groups
	return make_minimized_table() ;
}

Transition_Table * Minimizer::make_minimized_table(){
	unordered_map<int,unordered_map<string,int>> new_table;

	for(int i = 0 ; i < gs.groups_count(); i++){
		int item = gs.get_group(i).get_group_item();
		new_table[i] = unordered_map<string,int>();
		for(auto it = table[item].begin() ; it != table[item].end() ; it++){
			string input = it->first;
			int dest = it->second;
			new_table[i][input] = gs.find_group(dest);
		}
	}

	// get the group
	// for each item get its state
	// see the highest pirority
	// set it as the my state
	Transition_Table* new_transition_table = new Transition_Table(new_table);

	int start_state_id = start_state->get_id();

	int g_id = gs.find_group(start_state_id);

	for(int i = 0 ; i < gs.groups_count(); i++){
		priority p = in_valid;
		string token = "";
		get_highest(p,token,i);
		new_transition_table->add_state(new State(p,token,i));
	}
	new_transition_table->set_start_state_id(g_id);

	return new_transition_table;
}

void Minimizer::get_highest(priority& p , string& token , int i){

	vector<int> values = gs.get_group(i).get_values();
	for(unsigned int j = 0 ; j < values.size() ; j++){
		State* s = t_table->get_state(values[j]);
		if(saver.get_token_level(s->get_token()) > saver.get_token_level(token)){
			token = s->get_token();
			p = valid;
		}
	}
}

bool Minimizer::identical_groups(Groups g1 , Groups g2){
	if(g1.groups_count() != g2.groups_count()){
		return false;
	}
	int sz = g1.groups_count();

	vector<pair<bool,bool>> i_matrix(sz,make_pair(false,false));
	for(int i = 0 ; i < sz;i++){
		for(int j = 0 ; j < sz ; j++){
			if(i_matrix[i].first){
				break;
			}
			if(i_matrix[j].second){
				continue;
			}
			if(identical_group(g1.get_group(i),g1.get_group(j))){
				i_matrix[i].first = true;
				i_matrix[j].second = true;
			}
		}
	}
	for(int i = 0 ; i < sz ; i++){
		if(!i_matrix[i].first || !i_matrix[i].second){
			return false;
		}
	}
	return true;
}
bool Minimizer::identical_group(Group g1 , Group g2){
	if(g1.group_size() != g2.group_size()){
		return false;
	}
	vector<int> g1_values = g1.get_values();
	for(unsigned int i = 0 ; i < g1_values.size() ; i++){
		if(!g2.exist(g1_values[i])){
			return false;
		}
	}
	return true;
}
bool Minimizer::same_group(int first, int second){

	if(table[first].size() != table[second].size()){
		return false;
	}
	if(saver.get_token_level(t_table->get_state(first)->get_token()) !=
			saver.get_token_level(t_table->get_state(second)->get_token()) ){
		return false;
	}
	for(auto it = table[first].begin() ; it != table[first].end() ; it++){
		string input = it->first;
		int dest = it->second;
		if(table[second].find(input) == table[second].end()){
			return false;
		}
		int dest2 = table[second][input];
		int first_g_id = gs.find_group(dest);
		int second_g_id = gs.find_group(dest2);
		if(second_g_id != first_g_id){
			return false;
		}
	}
	// in the same group
	return true;
}

/*
unordered_map<int,unordered_map<char, int>> Minimizer::get_minimzed() {

	vector<char> inputs;

	for(auto it = table.begin() ; it!= table.end() ; it++){
		unordered_map<char, int> temp = it->second;
		for(auto it1 = temp.begin() ; it1 != temp.end() ; it1++){
			if(!count(inputs.begin(),inputs.end(),it1->first)){
				inputs.push_back(it1->first);
			}
		}
	}
	cout << "Hello from minimize";
	minimize(inputs);
	return build_minimized_table(inputs);
}
*/
