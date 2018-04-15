/*
 * Groups.h
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#ifndef GROUPS_H_
#define GROUPS_H_

#include "Group.h"
#include <vector>

class Groups {
public:
	/**
	 * add a Group to the list of groups: groups
	 */
	void add(Group g);

	/**
	 * find the group that-> node belongs to it
	 */
	int find_group(int node);

	int groups_count();

	Group get_group(int id);

	void add_node_to_group(int id, int node);

private:
	std::vector<Group> groups;
};


#endif /* GROUPS_H_ */
