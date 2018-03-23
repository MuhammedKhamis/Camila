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

public:
	std::vector<Group> groups;
};


#endif /* GROUPS_H_ */
