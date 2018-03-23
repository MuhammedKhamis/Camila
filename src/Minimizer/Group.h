/*
 * Group.h
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <bits/stdc++.h>
using namespace std;

class Group {
public:
	/**
	 * add a node to this group
	 */
	void add(int node);

	/**
	 * delete a node from this group
	 */
	void del(int node);

	/**
	 * check if this node belongs to this group
	 */
	bool exist(int node);

	vector<pair<int,int>> get_pairs();

	vector<int> get_values();

	int group_size();

	int get_group_item();

	/**
	 * print all nodes numbers of this group
	 */
	void print();

private:
	/**
	 * list of nodes belongs to this group
	 */
	set<int> group;
};

#endif /* GROUP_H_ */
