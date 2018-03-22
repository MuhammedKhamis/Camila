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

void Group::print(){
	for (set<int>::iterator it = group.begin(); it != group.end(); ++it) {
		cout<<*it<<' ';
	}
	cout<<'\n';
}
