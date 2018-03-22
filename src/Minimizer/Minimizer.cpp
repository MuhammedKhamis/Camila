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

void Minimizer::minimize(char inputs[]) {
	int size = sizeof(inputs) / sizeof(char);
	bool unstable = true;
	while (unstable) {
		unstable = false;
		for (int c = 0; c < size; ++c) {
			unstable |= sub_minimize(inputs[c]);
		}
	}
}

bool Minimizer::sub_minimize(char input) {
	bool stable = true, rep = true;
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
				stable = false;
				rep = true;
			}
		}
	}
	return stable;
}

unordered_map<int, unordered_map<char, int>> Minimizer::build_minimized_table(
		char inputs[]) {
	std::unordered_map<int, std::unordered_map<char, int>> m_table;
	for (unsigned int g_idx = 0; g_idx < g.groups.size(); ++g_idx) {
		Group g_ptr = g.groups[g_idx];
		set<int>::iterator it = g_ptr.group.begin();
		int g_num = g.find_group(*it);
		unordered_map<char, int> next_states = renaming_next_states(*it, inputs);
		m_table[g_num] = next_states;
	}
	return m_table;
}

unordered_map<char, int> Minimizer::renaming_next_states(int node, char inputs[]){
	unordered_map<char, int> next_states;
	int size = sizeof(inputs) / sizeof(char);
	for (int c = 0; c < size; ++c) {
		int g_num = g.find_group(table[node][inputs[c]]);
		next_states[inputs[c]] = g_num;
	}
	return next_states;
}
