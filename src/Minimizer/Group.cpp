/*
 * Group.cpp
 *
 *  Created on: 21/3/2015
 *      Author: Murad
 */

#include "Group.h"
#include <iostream>

using namespace std;

void Group::add(int node){
	group.insert(node);
}

void Group::del(int node){
	group.erase(node);
}

bool Group::exist(int node){
	if (group.find(node) != group.end()) {
		return true;
	}
	return false;
}

int Group::get_group_item(){
	return *group.begin();
}

void Group::print(){
	for (set<int>::iterator it = group.begin(); it != group.end(); ++it) {
		cout<<*it<<' ';
	}
	cout<<'\n';
}

vector<pair<int,int>> Group::get_pairs(){
	vector<pair<int,int>> p;
	for(auto it = group.begin(); it != group.end() ; it++){
		for(auto it1 = it ; it1 != group.end() ; it1++){
			p.push_back(make_pair(*it,*it1));
		}
	}
	return p;
}
vector<int> Group::get_values(){
	vector<int> values;
	for(auto it = group.begin() ; it != group.end() ; it++){
		values.push_back(*it);
	}
	return values;
}
int Group::group_size(){
	return group.size();
}
