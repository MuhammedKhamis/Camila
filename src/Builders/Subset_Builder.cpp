/*
 * Subset_Builder.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: muhammed
 */

#include "Subset_Builder.h"

void Subset_Builder::convert_to_DFA(Node* start){
	bfs(start);
	queue<pair<int,set<int>>> q;

	set<int> closure = eps_closure( {start->get_node_number()} );

	int state_number = 0;

	q.push(make_pair(state_number,closure));

	Dstates[state_number++] = closure;

	unordered_map<int,unordered_map<char,int>> table;

	while(!q.empty()){
		pair<int,set<int>> front = q.front();
		set<int> top = front.second;
		q.pop();



		unordered_map<char,vector<int>> temp;
		/*
		 *  get all possible inputs
		 *  o/p = set of s
		 * */
		for(auto it = top.begin(); it != top.end() ; it++){
			for(unsigned int i = 0; i < adjList[*it].size() ; i++){
				if(adjList[*it][i].first == lambda){
					continue;
				}
				string s = adjList[*it][i].first;
				char t = string_to_char(s);
				temp[t].push_back(adjList[*it][i].second);
			}
		}
		/*
		 *  make the set of states
		 *
		 * */
		for(auto it = temp.begin(); it != temp.end(); it++){

			set<int> next_closure = eps_closure(it->second);
			int index = appeared_before(next_closure);

			if(index == -1){
				index = state_number;
				q.push(make_pair(index,next_closure));
				Dstates[state_number++] = next_closure;
			}

			table[front.first][it->first] = index;
		}
	}
}

int Subset_Builder::appeared_before(set<int> new_Dstate){
	for(auto it = Dstates.begin() ; it != Dstates.end() ; it++){
		set<int> old_Dstate = it->second;
		if(new_Dstate.size() != old_Dstate.size()){
			continue;
		}
		bool res = true;
		for(auto it1 = new_Dstate.begin() ; it1 != new_Dstate.end() ; it1++){
			if(!old_Dstate.count(*it1)){
				res = false;
			}
		}
		if(res){
			return it->first;
		}
	}
	return -1;
}

void Subset_Builder::bfs(Node* start){

	vector<bool> visited (start->get_node_number()+1 , false);

	adjList.resize(visited.size());

	queue<Node*> q;
	q.push(start);
	while(!q.empty()){
		Node* top = q.front();
		q.pop();
		if(visited[top->get_node_number()]){
			continue;
		}
		if(top->get_priority() == valid){
			token_table[top->get_node_number()] = top->get_token();
		}
		visited[top->get_node_number()] = true;
		vector<Edge> edges = top->get_edges();
		for(unsigned int i = 0 ; i < edges.size() ; i++){
			adjList[top->get_node_number()]
			        .push_back(
			        		make_pair(
			        				edges[i].get_value(),edges[i].get_to_Node()->get_node_number()));
			q.push(edges[i].get_to_Node());
		}
	}
}

set<int> Subset_Builder::eps_closure(vector<int> start){
	set<int> return_set;
	queue<int> q;

	for(unsigned int i = 0 ; i < start.size();i++){
		q.push(start[i]);

	}
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(return_set.count(top)){
			continue;
		}
		return_set.insert(top);
		for(unsigned int i = 0 ; i < adjList[top].size() ; i++){
			if(adjList[top][i].first == lambda){
				q.push(adjList[top][i].second);
			}
		}
	}
	return return_set;
}



