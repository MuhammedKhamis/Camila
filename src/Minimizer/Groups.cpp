/*
 * Groups.cpp
 *
 *  Created on: 21/3/2018
 *      Author: Murad
 */

#include "Groups.h"

int Groups::find_group(int node){
	for (unsigned int i = 0; i < groups.size(); ++i) {
		if (groups[i].exist(node)) {
			return i;
		}
	}
	return -1;
}

void Groups::add(Group g){
		groups.push_back(g);
}
