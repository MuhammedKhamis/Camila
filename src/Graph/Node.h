/*
 * Node.h
 *
 *  Created on: Mar 14, 2018
 *      Author: muhammed
 */

#ifndef NODE_H_
#define NODE_H_

#include <bits/stdc++.h>
#include "../Enums.h"

using namespace std;


class Node{
public:
	vector<Edge>* get_edges();
	priority get_priority();
	void set_priority(priority p);
	void add_edge(Node* end, string value);
	void set_node_number();
	int get_node_number();
	static int node_counter;
private:
	vector<Edge> edges;
	priority p;
	int node_number;
};



#endif /* NODE_H_ */
