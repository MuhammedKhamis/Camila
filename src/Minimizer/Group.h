/*
 * Group.h
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#ifndef GROUP_H_
#define GROUP_H_

#include <set>

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

	/**
	 * print all nodes numbers of this group
	 */
	void print();

public:
	/**
	 * list of nodes belongs to this group
	 */
	std::set<int> group;
};

#endif /* GROUP_H_ */
